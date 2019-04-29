#include "double-stacked-queue.h"


using namespace std;

DoubleStackedQueue::DoubleStackedQueue(
) {

}

DoubleStackedQueue::~DoubleStackedQueue() {
    
}

bool DoubleStackedQueue::empty()const {
    return this->backStack.empty() && this->frontStack.empty();
}

void DoubleStackedQueue::enQueue(const QueueItem & item) {
    frontStack.push(item);
}

void DoubleStackedQueue::deQueue(QueueItem & rItem) {
    if(backStack.empty()) {
        while(!frontStack.empty()) {
            QueueItem tempItem; 
            frontStack.pop(tempItem);
            backStack.push(tempItem);
        }
    }
    if(!backStack.empty()) {
        backStack.pop(rItem);
    }
}
