/*
A manager of queue;
*/
#ifndef QUEUELIST_H
#define QUEUELIST_H

#include <list>
#include <map>
#include "queue.h"
#include <string>
using namespace std;
class QueueList{
    private:
        int maxQueue;
        map<string,Queue> queueMap;
    public:
        QueueList(int maxQueue);
        void deleteQueue(string queueName);
        void insertQueue(string queueName);
        void insertMessage(string queueName, string message);
        string getMessage(string queueName);
};
#endif // QUEUELIST_H_INCLUDED
