#include <zmq.h>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <json/json.h>
#include <list>
#include "queue.h"
using namespace std;
typedef list<string> StringList;
int main ()
{
    StringList messageList;

    Json::Reader reader;
    Json::Value value;

 // Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder_creater = zmq_socket (context, ZMQ_REP);
    void *responder_receive = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder_creater,"tcp://127.0.0.1:5555");
    rc = zmq_bind (responder_receive,"tcp://127.0.0.1:5556");
    while (1) {
        zmq_msg_t message;
        zmq_msg_init (&message);
        int size = zmq_msg_recv(&message,responder_creater,ZMQ_DONTWAIT);
        if (size != -1)
        {
            char *string = new char(size+1);
            memcpy(string,zmq_msg_data(&message),size);
            zmq_msg_close(&message);
            string[size] = 0;
            cout<<string<<endl;
            messageList.push_back(string);
            free(string);
            //printf ("Received Hello\n");
            zmq_send (responder_creater, "{\"code\":\"200\"}", 14, 0);
        }

        zmq_msg_init (&message);
        size = zmq_msg_recv(&message,responder_receive,ZMQ_DONTWAIT);
        if (size != -1)
        {
            if (!messageList.empty())
            {
                string strMessage = messageList.front();
                messageList.pop_front();
                cout<<"send: "<< strMessage<<endl;
                zmq_send (responder_receive,strMessage.c_str(),strMessage.length(),0);
            }
            else
            {
                zmq_send (responder_receive,"{\"info\":\"no message\"}",21,0);
                cout<<"send: "<< "{\"info\":\"no message\"}" <<endl;
            }
        }
     }
     return 0;
}
