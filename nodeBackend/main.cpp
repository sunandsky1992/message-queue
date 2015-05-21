#include <zmq.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <json/json.h>
#include "queueList.h"
using namespace std;
int main ()
{
    Json::Reader reader;
    Json::Value value;
    QueueList queueList(0);
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
        if (size != -1) {
            char str[size+1];
            memcpy(str,zmq_msg_data(&message),size);
            zmq_msg_close(&message);
            str[size] = 0;
            cout<<str<<endl;
            if (reader.parse(str, value)) {
                string content = value["message"].asString();
                string queue = value["queue"].asString();
                cout<<queue<<"  "<<content<<endl;
                zmq_send (responder_creater, "{\"code\":\"200\"}", 14, 0);
                queueList.insertMessage(queue, content);
            }
            else {
                zmq_send(responder_creater, "{\"code\":\"0\"}",12 ,0);
            }
        }
        zmq_msg_init (&message);
        size = zmq_msg_recv(&message,responder_receive,ZMQ_DONTWAIT);
        if (size != -1) {
            char str[size+1];
            memcpy(str,zmq_msg_data(&message),size);
            zmq_msg_close(&message);
            str[size] = 0;
            cout<<str<<endl;
            if (reader.parse(str,value)) {
                string queue = value["queue"].asString();
                cout<<queue<<endl;
                string strMessage = queueList.getMessage(queue);
                zmq_send (responder_receive,strMessage.c_str(),strMessage.length(),0);
            }
            else {
                zmq_send(responder_creater, "{\"code\":\"0\"}",12 ,0);
            }
        }

     }
     return 0;
}
