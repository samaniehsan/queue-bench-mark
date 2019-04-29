#include "circular-queue.h"
#include <cassert>

//credit
//much of this code inspired or copied from
//dotnet core implmentation of circular queue.

const int minimumGrow = 4;
const int growFactor = 200;
CircularQueue::CircularQueue(
): head(0), tail(0), size(0), capacity(0), arr(0) {
     
}

CircularQueue::~CircularQueue() {
    if(arr != 0) {
        delete [] arr;
    }
}

bool CircularQueue::empty()const {
    if(size == 0)
        return true;
}

void CircularQueue::enQueue(const QueueItem & item) {
  if(size == capacity) {
       int newcapacity = capacity * ((int)growFactor / 100);
       if (newcapacity < (capacity + minimumGrow)) {
          newcapacity = capacity + minimumGrow;
       }
     setCapacity(newcapacity);
  }

  arr[tail] = item;
  moveNext(tail);
  size++;
}

void CircularQueue::deQueue(QueueItem & rItem) {
    if (size == 0)
    {
        // this is really bad.
        assert(0 == size);
    }

    rItem = arr[head];
    QueueItem emptyItem;
    arr[head] = emptyItem;
    moveNext(head);
    size--;
}

void CircularQueue::copyArray(
    QueueItem* sourceArray,
    const int sourceIndex,
    QueueItem* destinationArray,
    const int destinationIndex,
    const int length) {
    int srcIndex;
    int i=0;
    for(i=0,srcIndex = sourceIndex; srcIndex <length;i++, srcIndex++) {
        int normalizedDestIndex = destinationIndex + i;
        destinationArray[normalizedDestIndex] = sourceArray[srcIndex]; 
    } 
}

void CircularQueue::setCapacity(const int newCapacity) {
     QueueItem* newarray = new QueueItem[newCapacity];
     if (size > 0) {

        if (head < tail)
        {
            copyArray(arr, head, newarray, 0, size);
            delete [] arr;
        }
        else
        {
            copyArray(arr, head, newarray, 0, size - head);
            copyArray(arr, 0, newarray, size - head, tail);
            delete [] arr;
        }
    }
    arr = newarray;
    capacity = newCapacity;
    head = 0;
    tail = (size == newCapacity) ? 0 : size;
}

// Increments the index wrapping it if necessary.
void CircularQueue::moveNext(int& index)
{
    int tmp = index + 1;
    if (tmp == capacity)
    {
        tmp = 0;
    }
    index = tmp;
}