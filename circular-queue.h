#ifndef _BENCH_MARK_QUEUECIRCULAR_
#define _BENCH_MARK_QUEUECIRCULAR_
#include "queue-item.h"

class CircularQueue {
public:
    CircularQueue();
    virtual ~CircularQueue();

    bool empty() const;
    void enQueue(const QueueItem & item);
    void deQueue(QueueItem &);
private:
    void setCapacity(const int newCapacity);
    void copyArray(
        QueueItem* sourceArray,
        const int sourceIndex,
        QueueItem* destinationArray,
        const int destinationIndex,
        const int length);
    void moveNext(int& index);
private:
    int tail, head;
    int size;
    int capacity; 
    QueueItem * arr;  
};

#endif
