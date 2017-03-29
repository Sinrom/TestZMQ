#include <iostream>
#include <string>
#include <zmq.hpp>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>

#define sleep(n) Sleep(n)
#endif

int main(int argc, char *argv[])
{
	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_REP);
	socket.bind("tcp://*:5555");

	while (true)
	{
		zmq::message_t rep;

		socket.recv(&rep);
		std::cout << "Recv msg: " << std::endl;

		sleep(1);

		zmq::message_t sendMsg(5);
		memcpy(sendMsg.data(), "SendM", 5);
		socket.send(sendMsg);
	}
	return 0;
}
