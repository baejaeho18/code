#include "MultiHeadList.h"
#include <iostream>

// Iterator
template <typename T>
T& MultiHeadList<T>::Iterator::operator*() {
    return curr->data;
}

template <typename T>
typename MultiHeadList<T>::Iterator& MultiHeadList<T>::Iterator::operator++() {
    if (curr) curr = curr->next;
    return *this;
}

template <typename T>
typename MultiHeadList<T>::Iterator MultiHeadList<T>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
typename MultiHeadList<T>::Iterator& MultiHeadList<T>::Iterator::operator--() {
    if (curr) curr = curr->prev;
    return *this;
}

template <typename T>
typename MultiHeadList<T>::Iterator MultiHeadList<T>::Iterator::operator--(int) {
    Iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
bool MultiHeadList<T>::Iterator::operator!=(const Iterator& other) const {
    return curr != other.curr;
}

template <typename T>
bool MultiHeadList<T>::Iterator::operator==(const Iterator& other) const {
    return curr == other.curr;
}


// ReverseIterator
template <typename T>
T& MultiHeadList<T>::ReverseIterator::operator*() {
    return curr->data;
}

template <typename T>
typename MultiHeadList<T>::ReverseIterator& MultiHeadList<T>::ReverseIterator::operator++() {
    if (curr) curr = curr->prev;
    return *this;
}

template <typename T>
typename MultiHeadList<T>::ReverseIterator MultiHeadList<T>::ReverseIterator::operator++(int) {
    ReverseIterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
typename MultiHeadList<T>::ReverseIterator& MultiHeadList<T>::ReverseIterator::operator--() {
    if (curr) curr = curr->next;
    return *this;
}

template <typename T>
typename MultiHeadList<T>::ReverseIterator MultiHeadList<T>::ReverseIterator::operator--(int) {
    ReverseIterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
bool MultiHeadList<T>::ReverseIterator::operator!=(const ReverseIterator& other) const {
    return curr != other.curr;
}

template <typename T>
bool MultiHeadList<T>::ReverseIterator::operator==(const ReverseIterator& other) const {
    return curr == other.curr;
}


// MultiHeadList
template <typename T>
int MultiHeadList<T>::headSize() {
    return headList.size();
}

template <typename T>
void MultiHeadList<T>::push_back(const T& data, int headIdx) {
    if (headIdx < 0 || headIdx >= headList.size()) {
        Node<T>* newNode = new Node<T>(data);
        headList.push_back(newNode);
    }
    else {
        Node<T>* tail = headList[headIdx];
        while (tail->next) tail = tail->next;
        Node<T>* newNode = new Node<T>(data);
        tail->next = newNode;
        newNode->prev = tail;
    }
}

template <typename T>
void MultiHeadList<T>::push_front(const T& data, int headIdx) {
    if (headIdx < 0 || headIdx >= headList.size()) {
        Node<T>* newNode = new Node<T>(data);
        headList.push_back(newNode);
    }
    else {
        Node<T>* head = headList[headIdx];
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head->prev = newNode;
        headList[headIdx] = newNode;
    }
}

template <typename T>
void MultiHeadList<T>::insert(Iterator pos, const T& data) {
    if (pos.curr) {
        Node<T>* newNode = new Node<T>(data);
        newNode->prev = pos.curr->prev;
        newNode->next = pos.curr;
        if (pos.curr->prev) pos.curr->prev->next = newNode;
        pos.curr->prev = newNode;
    }
}

template <typename T>
void MultiHeadList<T>::pop_back(int headIdx) {
    if (headIdx < 0 || headIdx >= headList.size()) return;
    Node<T>* tail = headList[headIdx];
    if (!tail) return;
    while (tail->next) tail = tail->next;
    if (tail->prev) tail->prev->next = nullptr;
    else headList[headIdx] = nullptr;
    delete tail;
}

template <typename T>
void MultiHeadList<T>::pop_front(int headIdx) {
    if (headIdx < 0 || headIdx >= headList.size()) return;
    Node<T>* head = headList[headIdx];
    if (!head) return;
    headList[headIdx] = head->next;
    if (head->next) head->next->prev = nullptr;
    delete head;
}

template <typename T>
void MultiHeadList<T>::merge(int frontHeadIdx, int backHeadIdx) {
    if (frontHeadIdx < 0 || frontHeadIdx >= headList.size() || backHeadIdx < 0 || backHeadIdx >= headList.size()) return;
    Node<T>* frontTail = headList[frontHeadIdx];
    while (frontTail->next) frontTail = frontTail->next;
    frontTail->next = headList[backHeadIdx];
    if (headList[backHeadIdx]) headList[backHeadIdx]->prev = frontTail;
    headList.erase(headList.begin() + backHeadIdx);
}

template <typename T>
bool MultiHeadList<T>::erase(const T& data, int targetHeadIdx) {
    if (targetHeadIdx < 0 || targetHeadIdx >= headList.size()) return false;
    Node<T>* current = headList[targetHeadIdx];
    while (current && current->data != data) current = current->next;
    if (current) {
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == headList[targetHeadIdx]) headList[targetHeadIdx] = current->next;
        delete current;
        return true;
    }
    return false;
}

template <typename T>
bool MultiHeadList<T>::erase(Iterator pos) {
    if (pos.curr) {
        if (pos.curr->prev) pos.curr->prev->next = pos.curr->next;
        if (pos.curr->next) pos.curr->next->prev = pos.curr->prev;
        delete pos.curr;
        return true;
    }
    return false;
}

template <typename T>
typename MultiHeadList<T>::Iterator MultiHeadList<T>::begin(int headIdx) {
    if (headIdx < 0 || headIdx >= headList.size()) return Iterator(nullptr);
    return Iterator(headList[headIdx]);
}

template <typename T>
typename MultiHeadList<T>::Iterator MultiHeadList<T>::end() {
    return Iterator(nullptr);
}

template <typename T>
typename MultiHeadList<T>::ReverseIterator MultiHeadList<T>::rbegin(int headIdx) {
    if (headIdx < 0 || headIdx >= headList.size()) return ReverseIterator(nullptr);
    Node<T>* tail = headList[headIdx];
    while (tail && tail->next) tail = tail->next;
    return ReverseIterator(tail);
}

template <typename T>
typename MultiHeadList<T>::ReverseIterator MultiHeadList<T>::rend() {
    return ReverseIterator(nullptr);
}
