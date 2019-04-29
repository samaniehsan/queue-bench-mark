#include "simple-stack.h"

SimpleStack::SimpleStack():m_node(0) {

}


SimpleStack::~SimpleStack() {
    if(m_node != 0) {
        Node * node = m_node;
        while(!empty()) {
            QueueItem rItem;
            pop(rItem);
        }
    }
}

bool SimpleStack::empty() const {
    if(m_node != 0) {
        return false;
    }
    return true;
}

void SimpleStack::push(const QueueItem & item) {
    Node * node = new Node();
    node->data = item;
    node->next = m_node;
    m_node = node;
}

void SimpleStack::pop(QueueItem & rItem) {
    if(m_node != 0) {
        rItem = m_node->data;
        Node * newHead = m_node->next;
        delete m_node;
        m_node = newHead;
    }
}
