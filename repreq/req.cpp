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
    zmq::context_t ctx(1);
    zmq::socket_t socket(ctx, ZMQ_REQ);

    std::cout << "Connecting to Server" << std::endl;
    socket.connect("tcp://localhost:5555");

    while (true)
    {
        zmq::message_t request(5);
        memcpy(request.data(), "Hello", 5);

        socket.send(request);

        zmq::message_t rep;
        socket.recv(&rep);

        std::cout << std::string((const char*)rep.data(), rep.size()) << std::endl;
    }

    return 0;
}
