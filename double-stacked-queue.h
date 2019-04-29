#ifndef _BENCH_MARK_DOUBLESTACKEDQUEUE_
#define _BENCH_MARK_DOUBLESTACKEDQUEUE_
#include "queue-item.h"
#include "simple-stack.h"

class DoubleStackedQueue {
public:
    DoubleStackedQueue();
    virtual ~DoubleStackedQueue();

    bool empty() const;
    void enQueue(const QueueItem & item);
    void deQueue(QueueItem &);
private:
    SimpleStack frontStack;
    SimpleStack backStack;
};

#endif
