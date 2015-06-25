#include "zmqHelper.h"
using namespace std;

zmqHelper::zmqHelper(string address, int type)
{
        context = zmq_ctx_new ();

        responder = zmq_socket (context, type);
        zmq_bind (responder,address.c_str());
}

string zmqHelper::receiveMsgWithoutWait()
{
        zmq_msg_t message;
        zmq_msg_init (&message);
        int size = zmq_msg_recv(&message,responder,ZMQ_DONTWAIT);
        if (size != -1) {
                char str[size+1];
                memcpy(str,zmq_msg_data(&message),size);
                zmq_msg_close(&message);
                str[size] = 0;
                string res(str);
                return res;
        }
        else
        {
                string res = "";
                return res;
        }
        zmq_msg_close(&message);
}

string zmqHelper::receiveMsgWait()
{
        zmq_msg_t message;
        zmq_msg_init(&message);
        int size = zmq_msg_recv(&message,responder,0);
        if (size != -1) {
                char str[size+1];
                memcpy(str,zmq_msg_data(&message),size);
                zmq_msg_close(&message);
                str[size] = 0;
                string res(str);
                return res;
        }
        else
        {
                string res = "";
                return res;
        }
        zmq_msg_close(&message);
}

void zmqHelper::sendMsg(char msg[])
{
        zmq_send (responder,msg,strlen(msg),0);
}

void zmqHelper::sendMsg(string msg)
{
        zmq_send (responder,msg.c_str(),msg.length(),0);
}
