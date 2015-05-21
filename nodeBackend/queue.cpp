#include "queue.h"
#include <iostream>
using namespace std;
Queue::Queue(string name) {
    this->queueName = name;
    this->queue.clear();
}
void Queue::setMaxLimit(int limit) {
    this->maxLimit = limit;
}

int Queue::getMaxLimit() {
    return this->maxLimit;
}

int Queue::getMessageLength() {
    return this->queue.size();
}
void Queue::setQueueName(string name) {
    this->queueName = name;
}

string Queue::getQueueName() {
    return this->queueName;
}

void Queue::clearQueue() {
    this->queue.clear();
}

string Queue::getFirstMessage() {
    string res = this->queue.front();
    this->queue.pop_front();
    return res;
}

void Queue::insertMessage(string message) {
    cout<<queue.size()<<endl;
    queue.push_back(message);
}


