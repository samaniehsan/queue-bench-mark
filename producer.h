
#ifndef _BENCH_MARK_PRODUCER_
#define _BENCH_MARK_PRODUCER_

class QueueWrapper;
class Producer {
public:
    Producer(QueueWrapper * pQueue);
    virtual ~Producer();
    void run(const unsigned int n);
private:
    QueueWrapper * m_pQueue;
};
#endif
