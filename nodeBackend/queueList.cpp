#include "queueList.h"
#include <iostream>
using namespace std;
QueueList::QueueList(int maxQueue){
    queueMap.clear();
    this->maxQueue = maxQueue;
}

void QueueList::deleteQueue(string queueName) {
    queueMap.erase(queueName);
};

void QueueList::insertQueue(string queueName) {
    Queue q(queueName);
    queueMap.insert(pair<string,Queue>(queueName,q));
};

void QueueList::insertMessage(string queueName, string message) {
    map<string, Queue>::iterator iter = queueMap.find(queueName);
    if (iter == queueMap.end()) {
            insertQueue(queueName);
            iter = queueMap.find(queueName);
        }
    iter->second.insertMessage(message);
};

string QueueList::getMessage(string queueName) {
    map<string, Queue>::iterator iter = queueMap.find(queueName);
    if (iter == queueMap.end()) {
            return "";
        }
    if (iter->second.getMessageLength()==0) {
        return "";
    }
    return iter->second.getFirstMessage();
}
