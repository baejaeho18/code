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
    vector<Node<T>*> headList;
public :
    class Iterator {
    public:
        Node<T>* curr;
        Iterator(Node<T>* node) : curr(node) {}
        T& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
    };
    class ReverseIterator{
    public:
        Node<T>* curr;
        ReverseIterator(Node<T>* node) : curr(node) {}
        T& operator*();
        ReverseIterator& operator++();
        ReverseIterator operator++(int);
        ReverseIterator& operator--();
        ReverseIterator operator--(int);
        bool operator!=(const ReverseIterator& other) const;
        bool operator==(const ReverseIterator& other) const;
    };

public:
    int headSize() {}
    void push_back(const T& data, int headIdx=-1) {}
    void push_front(const T& data, int headIdx=-1) {}
    void insert(Iterator pos, const T& data) {}
    void pop_back(int headIdx) {}
    void pop_front(int headIdx) {}
    void merge(int frontHeadIdx, int backHeadIdx) {}
    bool erase(const T& data, int targetHeadIdx) {}
    bool erase(Iterator pos) {}

    Iterator begin(int headIdx) {}
    Iterator end() {}
    ReverseIterator rbegin(int headIdx) {}
    ReverseIterator rend() {}
};

#endif