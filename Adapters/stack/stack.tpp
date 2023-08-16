#ifndef STACK_TPP
#define STACK_TPP

template <typename T>
Stack<T>::Stack() : m_size{0} {}

template <typename T>
Stack<T>::Stack(const Stack<T>& src) : container{src.container} {}
	

template <typename T>
Stack<T>::Stack(Stack<T>&& src)
{
	container = src.container;
}
template <typename T>
size_t Stack<T>::size() 
{
	return m_size;
}

template <typename T>
bool Stack<T>::empty()
{
	return m_size == 0;
}

template <typename T>
void Stack<T>::print()
{
	for (int i = 0; i < m_size; ++i) {
		std::cout << container[i] << " ";
	}
}

template <typename T>
void Stack<T>::push(const T& val)
{
	container.push_back(val);
	++m_size;
}

template <typename T>
void Stack<T>::pop()
{
	container[m_size - 1] = 0;
	--m_size;
}

template <typename T>
const T& Stack<T>::top()
{
	return container[m_size - 1];
}

#endif