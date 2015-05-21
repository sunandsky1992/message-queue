/*

*/
#ifndef QUEUE_H
#define QUEUE_H
#include "queue.h"
#include <list>
#include <string>
using namespace std;
class Queue{
    private:
        string queueName;
        list<string> queue;
        int maxLimit;
    public:
        Queue(string name);
        void setQueueName(string name);
        string getQueueName();
        void setMaxLimit(int n);
        int getMaxLimit();
        void clearQueue();
        string getFirstMessage();
        void insertMessage(string message);
        int getMessageLength();
};
#endif
