#ifndef _BENCH_MARK_SIMPLESTACK_
#define _BENCH_MARK_SIMPLESTACK_

#include "queue-item.h"

class Node{
public:
    QueueItem data;
    Node * next;
};

class SimpleStack {
public:
    SimpleStack();
    virtual ~SimpleStack();

    bool empty() const;
    void push(const QueueItem & item);
    void pop(QueueItem & rItem);
private:
    Node * m_node;
};

#endif
