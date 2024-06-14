#pragma once
#include <iostream>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    class Node {
    public:
        T value;
        Node* next;
        int priority;
        Node(T value, int priority) : value(value), next(nullptr), priority(priority) {}
    };
    Node* head;
    int size;
public:
    PriorityQueue() : head(nullptr), size(0) {}
    ~PriorityQueue();
    void enqueuePQ(T item, int priority);
    void dequeuePQ();
    bool isEmpty() const;
    T peek();
    void display();
    int getSize() const;
};

