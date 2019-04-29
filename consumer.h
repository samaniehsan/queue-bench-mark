
#ifndef _BENCH_MARK_CONSUMER_
#define _BENCH_MARK_CONSUMER_

class QueueWrapper;
class Consumer {
public:
    Consumer(QueueWrapper * pQueue, const bool verbose);
    virtual ~Consumer();
    void run(const unsigned int n);
private:
    QueueWrapper * m_pQueue;
    bool m_isVerbose;
};
#endif
