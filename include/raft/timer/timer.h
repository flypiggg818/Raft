#ifndef RAFT_PROJ_TIMER_HPP
#define RAFT_PROJ_TIMER_HPP

#include <functional>
#include <memory>
#include <boost/thread.hpp>
#include <functional>
#include <thread>

namespace SJTU {
	class Timer {
	public:
		Timer();

		~Timer();

		/// timer starts to count down.
		void Start();

		void Stop();

		void SetTimeOut(int, int);

		/// leave timeout action and time limit unchanged, just stop and restart, without repeat.
		void Reset();

		/**
		 * When a timer runs into the case of timeout, it behaves differently with respect to
		 * its current identity.
		 *
		 * For example:
		 * 1. If a follower timeouts, it transforms to candidate.
		 * 2. If a candidate timeouts, it remains candidate and tries election once again.
		 * 3. Is timeout possible for a leader? Well, I won't consider this issue at this early stage.
		 *
		 * In a word, a timer needs to be bound with different action for it to do when timeouts,
		 * and here is the interface for that.
		 *
		 * Note that BindAction needs to be invoked before Start in order to work properly.
		 *
		 *
		 * ans to 3. When leader timeouts, it sends out heartbeat, but this is a repetitive work.
		 * */
		void BindTimeOutAction(std::function<void()> f);

		/**
		 * This function is AddEvent member function inside the EventQueue class, which allows timer
		 * to insert whatever function it wants into EventQueue.
		 * */
		void BindPushEvent(std::function<void(std::function<void()>)> f);

	private:
		int high_time;   /// use boost::chrono lib later on.
		int low_time;
		std::function<void()> timeOutAction_;
		std::function<void(std::function<void()>)> pushEvent_;
		boost::thread th;
	};
};

#endif //RAFT_PROJ_TIMER_HPP
