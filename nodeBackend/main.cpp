#include <zmq.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <json/json.h>
#include "queueList.h"
#include "zmqHelper.h"
using namespace std;
int main ()
{
    Json::Reader reader;
    Json::Value value;
    QueueList queueList(0);
    zmqHelper creater("tcp://127.0.0.1:5555", ZMQ_REP);
    zmqHelper receive("tcp://127.0.0.1:5556", ZMQ_REP);
    while (1) {
        string msg;
        msg = creater.receiveMsgWithoutWait();

        if (msg!="") {
            char str[msg.length()];
            strcpy(str,msg.c_str());
            cout<<str<<endl;
            if (reader.parse(str, value)) {
                string content = value["message"].asString();
                string queue = value["queue"].asString();
                cout<<queue<<"  "<<content<<endl;
                creater.sendMsg("{\"code\":\"200\"}");
                queueList.insertMessage(queue, content);
            }
            else {
                creater.sendMsg("{\"code\":\"0\"}");
            }
        }

       msg = receive.receiveMsgWithoutWait();
        if (msg!="") {

            char str[msg.length()];
            strcpy(str,msg.c_str());
            cout<<str<<endl;
            if (reader.parse(str,value)) {
                string queue = value["queue"].asString();
                cout<<queue<<endl;
                string strMessage = queueList.getMessage(queue);
                receive.sendMsg(strMessage.c_str());
            }
            else {
                receive.sendMsg("{\"code\":\"0\"}");
            }
        }
     }
     return 0;
}
