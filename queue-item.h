#ifndef _BENCH_MARK_QUEUEITEM_
#define _BENCH_MARK_QUEUEITEM_



class QueueItem {
    int index;
    char description[11];
public:
    QueueItem();
    QueueItem(
        const int index,
        const char * description);
    QueueItem(const QueueItem &);

    QueueItem& operator=(const QueueItem& other);
};

#endif
