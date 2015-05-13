/*

*/
#ifndef QUEUE_H
#define QUEUE_H
#include <list>
#include <string>
using namespace std;
class Queue{
    private:
        string queueName;
        list<string> queueList;
        int maxLimit;
    public:
        Queue();
        void setQueueName(string name);
        string getQueueName();
        void setMaxLimit(int n);
        int getMaxLimit();
        void clearQueue();
        string getFirstMessage();
        int getMessageLength();
};
#endif
