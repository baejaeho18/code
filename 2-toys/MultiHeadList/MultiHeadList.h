#pragma once
#ifndef MULTIHEADLIST_H
#define MULTIHEADLIST_H

#include <vector>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

template <typename T>
class MultiHeadList {
private:
    std::vector<Node<T>*> headList;
    
public :
    class Iterator;
    class ReverseIterator;

public:
    int headSize() { return headList.size(); }
    void push_back(const T& data, int headIdx=-1) {
        if (headIdx < 0 || headList.size() <= headIdx) {
            Node<T>* newNode = new Node<T>(data);
            headList.push_back(newNode);
        }
        else {
            Node<T>* tail = headList[headIdx];
            while (tail->next)
                tail = tail->next;
            Node<T>* newNode = new Node<T>(data);
            tail->next = newNode;
            newNode->prev = tail;
        }
    }
    void push_front(const T& data, int headIdx = -1) {
        if (headIdx < 0 || headList.size() <= headIdx) {
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
    void insert(Iterator pos, const T& data) {
        if (pos.curr) {
            Node<T>* newNode = new Node<T>(data);
            newNode->prev = pos.curr->prev;
            newNode->next = pos.curr;
            if (pos.curr->prev)
                pos.curr->prev->next = newNode;
            else {
                for (int i = 0; i < headList.size(); i++) {
                    if (headList[i] == pos.curr) {
                        headList[i] = newNode;
                        break;
                    }
                }
            }
            pos.curr->prev = newNode;
        }
    }
    void pop_back(int headIdx) {
        if (headIdx < 0 || headList.size() <= headIdx)
            return;
        Node<T>* tail = headList[headIdx];
        if (!tail) return;
        while (tail->next) tail = tail->next;
        if (tail->prev)
            tail->prev->next = nullptr;
        else
            headList[headIdx] = nullptr;

        if (headList[headIdx] == nullptr)
            headList.erase(headList.begin() + headIdx);
        delete tail;
    }
    void pop_front(int headIdx) {
        if (headIdx < 0 || headList.size() <= headIdx)
            return;
        Node<T>* head = headList[headIdx];
        if (!head) return;
        headList[headIdx] = head->next;
        if (head->next)
            head->next->prev = nullptr;

        if (headList[headIdx] == nullptr) {
            headList.erase(headList.begin() + headIdx);
        }
        delete head;
    }
    void merge(int frontHeadIdx, int backHeadIdx) {
        if (frontHeadIdx < 0 || headList.size() <= frontHeadIdx
            || backHeadIdx < 0 || headList.size() <= backHeadIdx)
            return;
        Node<T>* frontTail = headList[frontHeadIdx];
        while (frontTail->next)
            frontTail = frontTail->next;
        frontTail->next = headList[backHeadIdx];
        if (headList[backHeadIdx])
            headList[backHeadIdx]->prev = frontTail;
        headList.erase(headList.begin() + backHeadIdx);
    }
    bool erase(const T& data, int targetHeadIdx) {
        if (targetHeadIdx < 0 ||  headList.size() <= targetHeadIdx)
            return false;
        Node<T>* current = headList[targetHeadIdx];
        while (current && current->data != data)
            current = current->next;
        //if (current)
        //    return erase(Iterator(current));
        if (current) {
            if (current->prev)
                current->prev->next = nullptr;
            if (current->next) {
                current->next->prev = nullptr;
                headList.push_back(current->next);
            }
            if (current == headList[targetHeadIdx])
                headList.erase(headList.begin() + targetHeadIdx);
        }
        return false;
    }
    bool erase(Iterator pos) {
        if (pos.curr) {
            if (pos.curr->prev)
                pos.curr->prev->next = nullptr;
            if (pos.curr->next) {
                pos.curr->next->prev = nullptr;
                headList.push_back(pos.curr->next);
            }
            for (int i = 0; i < headList.size(); i++) {
                if (headList[i] == pos.curr) {
                    headList.erase(headList.begin() + i);
                    break;
                }
            }
            delete pos.curr;
            return true;
        }
        return false;
    }

    Iterator begin(int headIdx) {
        if (headIdx < 0 || headIdx >= headList.size())
            return Iterator(nullptr);
        return Iterator(headList[headIdx]);
    }
    Iterator end() { return Iterator(nullptr); }
    ReverseIterator rbegin(int headIdx) {
        if (headIdx < 0 || headIdx >= headList.size())
            return ReverseIterator(nullptr);
        Node<T>* tail = headList[headIdx];
        while (tail && tail->next)
            tail = tail->next;
        return ReverseIterator(tail);
    }
    ReverseIterator rend() { return ReverseIterator(nullptr); }
};

template <typename T>
class MultiHeadList<T>::Iterator {
public:
    Node<T>* curr;
    Iterator(Node<T>* node) : curr(node) {}
    T& operator*() { return curr->data; };
    Iterator& operator++() { if (curr) curr = curr->next; return *this; };
    Iterator& operator--() { if (curr) curr = curr->prev; return *this; };
    Iterator& operator++(int) { Iterator tmp = *this; ++(*this); return tmp; };
    Iterator& operator--(int) { Iterator tmp = *this; --(*this); return tmp; };
    Iterator& operator+(int n) { for (int i = 0; i < n && curr; ++i) curr = curr->next; return *this; };
    Iterator& operator-(int n) { for (int i = 0; i < n && curr; ++i) curr = curr->prev; return *this; };
    bool operator!=(const Iterator& other) const { return curr != other.curr; };
    bool operator==(const Iterator& other) const { return curr == other.curr; };
};

template <typename T>
class MultiHeadList<T>::ReverseIterator {
public:
    Node<T>* curr;
    ReverseIterator(Node<T>* node) : curr(node) {}
    T& operator*() { return curr->data; };
    ReverseIterator& operator++() { if (curr) curr = curr->prev; return *this; };
    ReverseIterator& operator--() { if (curr) curr = curr->next; return *this; };
    ReverseIterator& operator++(int) { Iterator tmp = *this; ++(*this); return tmp; };
    ReverseIterator& operator--(int) { Iterator tmp = *this; --(*this); return tmp; };
    ReverseIterator& operator+(int n) { for (int i = 0; i < n && curr; ++i) curr = curr->next; return *this; };
    ReverseIterator& operator-(int n) { for (int i = 0; i < n && curr; ++i) curr = curr->prev; return *this; };
    bool operator!=(const ReverseIterator& other) const { return curr != other.curr; };
    bool operator==(const ReverseIterator& other) const { return curr == other.curr; };
};

#endif