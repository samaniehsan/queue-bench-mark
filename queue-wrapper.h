#ifndef _BENCH_MARK_QUEUEWRAPPER_
#define _BENCH_MARK_QUEUEWRAPPER_

#include "queue-item.h"
#include "circular-queue.h"
#include "double-stacked-queue.h"
#include <queue>

enum QueueType {
    QueueType_DoubleEnded,
    QueueType_CircularArray,
    QueueType_DoubleStacks
};

class QueueWrapper {
public:
    QueueWrapper(const QueueType);
    virtual ~QueueWrapper();

    bool empty() const;
    void enQueue(const QueueItem & item);
    void deQueue(QueueItem &);
private :
    QueueType m_queueType;
    std::queue<QueueItem> * m_queue;
    CircularQueue * m_circularQueue;
    DoubleStackedQueue * m_doubleStackQueue;
};

#endif
