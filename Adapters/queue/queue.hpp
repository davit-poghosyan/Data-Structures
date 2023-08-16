#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "/home/davit/Desktop/data_structures/list/singly_list/singlyList.hpp"

template <typename T>
class Queue
{
private:
    SinglyList<T> container;
    size_t m_size;
public:
    Queue();
    Queue(const Queue<T>&);
    Queue(Queue<T>&&);
    const T& front();
    bool empty();
    size_t size();
    void push(const T&);
    void pop();
};

#include queue.tpp

#endif