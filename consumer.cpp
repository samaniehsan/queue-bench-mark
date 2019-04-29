#include "consumer.h"

#include "queue-wrapper.h"
#include "queue-item.h"
#include <stdio.h> 
#include <iostream>

using namespace std;

Consumer::Consumer(
    QueueWrapper * pQueue,
    const bool verbose
):m_pQueue(pQueue), m_isVerbose(verbose) {
}

Consumer::~Consumer() {
    
}

void Consumer::run(const unsigned int n) {
    unsigned int i;
    for(i = 0; i < n; i++) {
        QueueItem item;
        m_pQueue->deQueue(item);

        if(m_isVerbose) {
            int index = item.getIndex();
            char sz[22] = {0};
            item.getDescription(&sz[0]);
            cout<<"index:"<<index<<",description:"<<&sz[0]<<endl;
        }
    }
}