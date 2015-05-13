#include<queue.h>
Queue::Queue(string name) {
    this.queueName = name;
    this.queueList.clear;
}

void Queue::setMaxLimit(int limit) {
    this.maxLimit = limit;
}

int Queue::getMaxLimit() {
    return this.maxLimit;
}

int Queue::getMessageLength() {
    return this.queueList.size();
}
void Queue::setQueueName(string name) {
    this.queueName = name;
}

string Queue::getQueueName() {
    return this.queueName;
}

void Queue::clearQueue() {
    this.queueList.clear();
}

string Queue::getFirstMessage() {
    return this.queueList.pop_front();
}


