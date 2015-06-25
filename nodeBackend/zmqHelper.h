#ifndef ZMQHELPER_H_INCLUDED
#define ZMQHELPER_H_INCLUDED
#include  <string>
#include <cstring>
#include <zmq.h>
using namespace std;
class zmqHelper
{
        private:
                void *context;
                void *responder;
        public:
                zmqHelper(string address, int type);
                void sendMsg(string msg);
                void sendMsg(char msg[]);
                string receiveMsgWait();
                string receiveMsgWithoutWait();
};

#endif // ZMQHELPER_H_INCLUDED
