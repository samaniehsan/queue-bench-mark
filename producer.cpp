#include "producer.h"
#include "stdio.h"
#include <time.h> 

#include "queue-item.h"
#include "queue-wrapper.h"

Producer::Producer(
    QueueWrapper * pQueue
):m_pQueue(pQueue) {

}

Producer::~Producer() {
    
}


void Producer::run(const unsigned int n) {
    unsigned int i;
    for(i = 0; i < n; i++) {
        int val = i + 1000;
        timespec tp;
        clock_gettime(CLOCK_MONOTONIC, &tp);
        char sz[11] = { 0 };
        sprintf(&sz[0], "%lu", tp.tv_nsec);
        QueueItem item(val,sz);
        m_pQueue->enQueue(item);
    }
}