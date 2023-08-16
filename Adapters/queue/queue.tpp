
template <typename T>
Queue<T>::Queue() : m_size{0} {}

template <typename T>
Queue<T>::Queue(const Queue<T>& src) : m_size{src.m_size}, container{src.container} {}

template <typename T>
Queue<T>::Queue(Queue<T>&& src) 
{   
    m_size = src.m_size;
    container = src.container;

    src.m_size = 0;    
}

template <typename T>
const T& Queue<T>::front()
{
    Node<T>* node;
    node = container.head->next;
    return node->data;
}

template <typename T>
bool Queue<T>::empty()
{
    return m_size == 0;
}

template <typename T>
size_t Queue<T>::size()
{
    return m_size;
}
template <typename T>
void Queue<T>::push(const T& val) 
{
    container.insertFront(val);
    ++m_size;
}

template <typename T>
void Queue<T>::pop()
{
    container.pop();
}
