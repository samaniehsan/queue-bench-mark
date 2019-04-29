#include "queue-wrapper.h"


using namespace std;

QueueWrapper::QueueWrapper(
    const QueueType queueType
): m_queueType(queueType),
    m_queue(0),
    m_circularQueue(0), 
    m_doubleStackQueue(0) {
     
}
QueueWrapper::~QueueWrapper() {
    if(m_queue != 0) {
        delete m_queue;
    }
    if(m_circularQueue != 0) {
        delete m_circularQueue;
    }
    if(m_doubleStackQueue != 0) {
        delete m_doubleStackQueue;
    }
}

bool QueueWrapper::empty()const {
    switch(m_queueType) {
        case QueueType_DoubleEnded:
            return m_queue->empty();
        case QueueType_CircularArray:
            return m_circularQueue->empty();
            
        case QueueType_DoubleStacks:
            return m_doubleStackQueue->empty();
    }
}

void QueueWrapper::enQueue(const QueueItem & item) {
    switch(m_queueType) {
        case QueueType_DoubleEnded:
            m_queue->push(item);
            break;
        case QueueType_CircularArray:
            m_circularQueue->enQueue(item);
            break;
        case QueueType_DoubleStacks:
            m_doubleStackQueue->enQueue(item);
            break;
    }
    
}

void QueueWrapper::deQueue(QueueItem & rItem) {
    switch(m_queueType) {
        case QueueType_DoubleEnded: {
            QueueItem & item = m_queue->front();
            rItem = item;
            m_queue->pop();
            break;
        }            
        case QueueType_CircularArray: {
            m_circularQueue->deQueue(rItem);
            break;
        }            
        case QueueType_DoubleStacks: {
            m_doubleStackQueue->deQueue(rItem);
            break;
        }
    }
}
