#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <zmq.hpp>

using namespace std;

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

		this_thread::sleep_for(chrono::milliseconds(100));
		cout << string((const char*)rep.data(), rep.size()) << endl;

		zmq::message_t sendMsg(5);
		memcpy(sendMsg.data(), "SendM", 5);
		socket.send(sendMsg);
	}
	return 0;
}
