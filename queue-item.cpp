#include "queue-item.h"

#include <string.h>

QueueItem::QueueItem() {
    index = 0;
    memset(&description, '\0', 22);
}

QueueItem::QueueItem(
    const int index,
    const char * description) {
    this->index = index;
    memcpy(&this->description[0], description, 21);
}

QueueItem::QueueItem(const QueueItem & item) {
    index = item.index;
    memcpy(&description[0], &item.description, 22);
}

QueueItem& QueueItem::operator=(const QueueItem& other) {
    this->index = other.index;
    memcpy(&this->description[0], other.description, 22);
    return *this;
}

int QueueItem::getIndex() const {
    return this->index;
}

void QueueItem::getDescription(
    char * sz
)const {
    memset(&sz[0], 0, 22);
    memcpy(&sz[0], description, 21);
}
