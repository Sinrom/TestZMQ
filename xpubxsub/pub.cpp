#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <zmq.hpp>

using namespace std;

zmq::message_t Str2Msg_t(const string &strMsg)
{
    zmq::message_t zmqMsg(strMsg.size());
    memcpy(zmqMsg.data(), strMsg.data(), strMsg.size());

    return zmqMsg;
}

int main(int argc, char *argv[])
{
    zmq::context_t ctx(1);
    zmq::socket_t socket(ctx, ZMQ_PUB);

    socket.connect("tcp://localhost:5559");
    string strFilter = "flt";
    string strMsg = "";
    int i = 0;
    while (true)
    {
        strMsg = to_string(i++);

        zmq::message_t filter = Str2Msg_t(strFilter);
        zmq::message_t sendMsg = Str2Msg_t(strMsg);

        socket.send(filter, ZMQ_SNDMORE);
        socket.send(sendMsg);

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
