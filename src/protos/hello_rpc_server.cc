#ifndef RAFT_PROJ_HELLO_RPC_SERVER_HPP
#define RAFT_PROJ_HELLO_RPC_SERVER_HPP

#include "hello.grpc.pb.h"
#include <iostream>
#include <cstring>
#include <mutex>
#include <grpc/grpc.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>
#include <boost/thread/lock_guard.hpp>

class HelloImpl final : public HelloService::Service {
public:
	HelloImpl() {}

	grpc::Status SayHello(grpc::ServerContext *context, const HelloRequest *request,
												HelloResponse *response) override {
		response->set_reply("hello client, your msg is " + request->greeting());
		return grpc::Status::OK;
	}
};

int main() {
	std::string addr = "0.0.0.0:5000";
	HelloImpl service;
	grpc::ServerBuilder builder;
	builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	auto server = builder.BuildAndStart();
	std::cout << "Server listening on " << addr << std::endl;
	server->Wait();

	return 0;
}

#endif //RAFT_PROJ_HELLO_RPC_SERVER_HPP
