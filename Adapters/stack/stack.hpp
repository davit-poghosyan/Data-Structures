#ifndef STACK_HPP
#define STACK_HPP

#include "/home/davit/Desktop/data_structures/Vector/vector.hpp"
#include <iostream>

template <typename T>
class Stack
{
private:
	Vector<T> container;
	int m_size;
public:
	explicit Stack();
	explicit Stack(const Stack<T>&);
	explicit Stack(Stack<T>&&);
	size_t size();
	bool empty();
	void print();

	void push(const T&);
	void pop();
	const T& top();
};

#include "stack.tpp"

#endif
