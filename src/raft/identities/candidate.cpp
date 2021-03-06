#include <future>
#include "../../../include/raft/identities/candidate.h"
#include "../../../include/raft/raft_proto/raft_server.h"

// #define  _NOLOG

namespace SJTU {
	Candidate::~Candidate() {}

	void Candidate::init() {
#ifndef _NOLOG
		printf("init to be candidate...\n");
#endif
		timer_.SetTimeOut(info.get_electionTimeout(), info.get_electionTimeout() * 2);
		timer_.Start();

		transforming = false;

		++state_.currentTerm;
		state_.votedFor.clear();
		votesReceived = 1;
		state_.votedFor = info.get_local();

		if (votesReceived > info.get_srvList().size() / 2) {
			identity_transformer(LeaderNo);
			return;
		}
		RequestVote();
	}

	void Candidate::leave() {
		transforming = true;

		votesReceived = 0;

		for (size_t i = 0; i < client_ends_.size(); ++i) {
			if (client_ends_[i]->th.joinable()) {
				client_ends_[i]->th.interrupt();
				client_ends_[i]->th.join();
			}
		}
		timer_.Stop();
	}

	/**
	 * This function is pushed by timer into event queue instead of executing by timer.
	 * */
	void Candidate::TimeOutFunc() {
		identity_transformer(CandidateNo);
	}

	void Candidate::RequestVote() {
		printf("clientSize %lu\n", client_ends_.size());
		for (size_t i = 0; i < client_ends_.size(); ++i) {
			if (client_ends_[i]->id == info.get_local())
				continue;
			if (client_ends_[i]->th.joinable()) client_ends_[i]->th.join();
			client_ends_[i]->th = boost::thread([this, i]() mutable {
				PbRequestVoteRequest request = MakeVoteRequest();

				PbRequestVoteResponse response;
				grpc::ClientContext context;

				context.set_deadline(std::chrono::system_clock::now() + std::chrono::milliseconds(PEER_TIMEOUT_MILLISECOND));
				grpc::Status status = client_ends_[i]->stub_->RequestVoteRPC(&context, request, &response);

				if (!status.ok()) {
					std::cout << status.error_code() << ": " << status.error_message() << std::endl;
					return;
				}

#ifndef _NOLOG
//				printf("Candidate received response from other server...\n");
//				printf("it says: term %lld, requestVote %d\n", response.term(), int(response.votegranted()));
#endif
				boost::unique_lock<boost::shared_mutex> lk1(state_.curTermMtx, boost::defer_lock);
				boost::unique_lock<boost::shared_mutex> lk2(state_.votedForMtx, boost::defer_lock);
				boost::lock(lk1, lk2);

				if (state_.currentTerm < response.term()) {
//					printf("candidate term smaller than other server's term, transform to follower...\n");
//					fprintf(stderr, "candidate transform to follower, asynchronous disaster may happen.\n");
					state_.currentTerm = response.term();
					state_.votedFor.clear();
					lk1.unlock();
					lk2.unlock();
					identity_transformer(FollowerNo);
					return;
				}
				lk1.unlock();
				lk2.unlock();

				if (response.votegranted())
					++votesReceived;


				if (votesReceived > info.get_srvList().size() / 2) {
					if (transforming) {
#ifndef _NOLOG
//						printf("There has been one identical transformation task undergoing... returning..\n");
#endif
						return;
					}
//					fprintf(stderr, "synchronous problem in candidate to leader transformation\n");
					transforming = true;

#ifndef _NOLOG
//					printf("There are %lu servers in total. %d votes received, start to transform to leader...\n",
//								 info.get_srvList().size(), (int) votesReceived);
//					printf("transforming to leader\n");
#endif
					/**
					 * Because transformation invokes .interruption(), after it there cannot be any call to transform identity.
					 * */
					try {
						boost::this_thread::interruption_point();
						identity_transformer(LeaderNo);
					}
					catch (boost::thread_interrupted &) {
//						printf("candidate requestVotes thread being interrupted, returning...\n");
						return;
					}
				}
			});
		}
	}

	/**
	 * access inner data member, synchronize it.
	 * */
	PbRequestVoteRequest Candidate::MakeVoteRequest() {
		boost::shared_lock<boost::shared_mutex> lk1(state_.curTermMtx, boost::defer_lock);
		boost::shared_lock<boost::shared_mutex> lk2(state_.logMasterMtx, boost::defer_lock);
		boost::lock(lk1, lk2);

		CppRequestVoteRequest request(state_.currentTerm, info.get_local(), state_.log.back().entryIndex,
																	state_.log.back().term);
		return request.Convert();
	}


};
