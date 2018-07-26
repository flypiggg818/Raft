#include "../../include/raft/raft.h"
#include "../../include/raft/event_queue/event_queue.h"
#include "../../include/raft/timer/timer.h"

#include <iostream>

namespace SJTU {
	struct Raft::Impl {
		EventQueue eventQueue_;
		Timer timer_;

	};

	Raft::Raft() : pImpl(std::make_unique<Impl>()) {}

	Raft::~Raft() = default;

	void Raft::init() {
		printf("raft is initting...\n");
		printf("raft is binding terminate action...\n");

		pImpl->timer_.BindPushEvent(std::bind(&EventQueue::addEvent, &pImpl->eventQueue_, std::placeholders::_1));
		pImpl->timer_.BindTimeOutAction([] {
			std::cout << "timer's terminate action is triggered" << std::endl;
		});

//		pImpl->timer_.BindTimeOutAction(std::bind(&EventQueue::addEvent, &pImpl->eventQueue_, [] {
//			std::cout << "timer's terminate action is triggered" << std::endl;
//		}));
	}

	void Raft::Start() {
		pImpl->eventQueue_.Start();
		pImpl->timer_.Start();
	}

	void Raft::Stop() {
		pImpl->eventQueue_.Stop();
		pImpl->timer_.Stop();
	}
};
