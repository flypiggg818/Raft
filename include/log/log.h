#ifndef RAFT_PROJ_LOG_H
#define RAFT_PROJ_LOG_H

/**
 * A container of one entry of log information.
 * */
namespace SJTU {
	struct Log {
		std::string command;
		int term;
	};
};

#endif //RAFT_PROJ_LOG_H
