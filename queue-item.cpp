#include "queue-item.h"

#include <string.h>

QueueItem::QueueItem() {
    index = 0;
    memset(&description, 0, 11);
}

QueueItem::QueueItem(
    const int index,
    const char * description) {
    this->index = index;
    memcpy(&this->description, description, 11);
}

QueueItem::QueueItem(const QueueItem & item) {
    index = item.index;
    memcpy(&description, &item.description, 11);
}

QueueItem& QueueItem::operator=(const QueueItem& other)
{
    this->index = other.index;
    memcpy(&this->description, other.description, 11);
    return *this;
}