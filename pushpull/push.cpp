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

string Msg_t2Str(zmq::message_t &msg)
{
    return string((const char*)msg.data(), msg.size());
}

int main (int argc, char *argv[])
{
    zmq::context_t ctx(1);
    zmq::socket_t socket(ctx, ZMQ_PUSH);
    //zmq::socket_t socket(ctx, ZMQ_PULL);
    socket.bind("tcp://*:5555");
    //socket.connect("tcp://localhost:5555");

    string strA = "";
    int i = 0;
    while (true)
    {
        strA = to_string(i++);
        zmq::message_t sendMsg = Str2Msg_t(strA);

        socket.send(sendMsg);

        //zmq::message_t recvMsg;
        //socket.recv(&recvMsg);
        //cout << "recvMsg: " << Msg_t2Str(recvMsg) << endl;

        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}
