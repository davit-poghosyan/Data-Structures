#ifndef VECTOR_TPP
#define VECTOR_TPP


template <typename T>
void Vector<T>::print(){
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << "  ";
    }
}

template <typename T>
constexpr void Vector<T>::verifySize(size_t size) const
{
    if (size >= m_size || size < 0) {
        throw std::out_of_range{"out of range"};
    }
}


template <typename T>
constexpr void Vector<T>::swap(Vector<T>& other) noexcept
{
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_arr, other.m_arr);
}


template <typename T>
constexpr void swap(Vector<T>& first, Vector<T>& second) noexcept
{
    first.swap(second);
}


template <typename T>
constexpr Vector<T>::Vector() noexcept
{
    m_size = 0;
    m_capacity = 0;
    m_arr = nullptr;
}

template <typename T>
constexpr Vector<T>::Vector(const Vector<T>& src) : m_size {src.size()}, m_capacity {src.capacity()}
{
    m_arr = new T [m_capacity];
    for (int i = 0; i < m_size; ++i) {
        this->m_arr[i] = src.m_arr[i];
    }
}

template <typename T>
constexpr Vector<T>& Vector<T>::operator=(const Vector& src)
{
    if (this == &src) {
        return *this;
    }

    m_size = src.size();
    m_capacity = src.capacity();
    delete[] m_arr;

    m_arr = new T [m_capacity];
    for (size_t i = 0; i < m_size; ++i) {
        m_arr[i] = src.at(i);
    }

    return *this;
}

template <typename T>
constexpr Vector<T>::Vector(Vector&& src) noexcept
{
    swap(src);
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_arr;
}


template <typename T>
constexpr Vector<T>& Vector<T>::operator=(Vector&& src) noexcept
{
   swap(*this, src);
   return *this;    
}

template <typename T>
constexpr Vector<T>::Vector(std::initializer_list<T> list)
{
    m_capacity = list.size() * 2;
    m_size = list.size();
    m_arr = new T [m_capacity];

  
    int i = 0;
    for (auto element : list) {
        m_arr[i] = element;
        ++i;
    }
}

template <typename T>
constexpr T& Vector<T>::operator[](size_t pos) const
{
    verifySize(pos);   
    return m_arr[pos];
}


template <typename T>
constexpr T& Vector<T>::at(size_t pos) const
 {
    verifySize(pos);
    return m_arr[pos];
 }

template <typename T>
constexpr T& Vector<T>::front() const
{
    if (m_arr){
        return *m_arr;
    }
    throw std::exception();
}

template <typename T>
constexpr T& Vector<T>::back() const
{
    if (m_arr) {
        return m_arr[m_size - 1];
    }
    throw std::exception();
}

template <typename T>
constexpr bool Vector<T>::empty() const noexcept
{
    if(m_arr){
        return false;
    }
    return true;
}

template <typename T>
constexpr void Vector<T>::resize(size_t new_cap)
{
    if (m_capacity< new_cap){
        m_capacity = new_cap;
        T* tmp = new T [m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        delete m_arr;
        m_arr = tmp;
        tmp = nullptr;
    }
    
    
}

template <typename T>
constexpr void Vector<T>::shrink_to_fit()
{
    if(m_capacity != m_size) {
        m_capacity = m_size;
        T* tmp = new T [m_capacity];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        delete m_arr;
        m_arr = tmp;
        tmp = nullptr;
    }
}

template <typename T>
constexpr void Vector<T>::clear() noexcept
{
    if(m_arr) {
    delete[] m_arr;
    m_size = 0;
    m_arr = new T [m_capacity];
    }
}

template <typename T>
constexpr void Vector<T>::insert(size_t pos, const T& value) 
{
    if(m_size == m_capacity) {
        m_capacity = m_capacity * 2;
    }
    T* tmp = new T [m_capacity];
    size_t i = 0;
    for (i; i < pos; ++i) {
        tmp[i] = m_arr[i];
    }  
    tmp[i] = value;
    ++i;
    for (i; i < m_size + 1; ++i) {
        tmp[i] = m_arr[i - 1];

    }
    delete m_arr;
    m_arr = tmp;
    tmp = nullptr;
    ++m_size;
        
    
      
}

template <typename T>
constexpr void Vector<T>::push_back(const T& value)
{
    if (m_size + 1 > m_capacity) {
        m_capacity = m_capacity * 2;
        T* tmp = new T [m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
        tmp = nullptr;
    } 
    m_arr[m_size] = value;
    ++m_size;
}
template <typename T>
constexpr void Vector<T>::pop_back()
{
    m_arr[m_size - 1] = 0;
    --m_size;
}


template <typename T> 
constexpr size_t Vector<T>::size() const noexcept
{
    return m_size;
}

template <typename T>
constexpr size_t Vector<T>::capacity() const noexcept
{
    return m_capacity;
}

template <typename T>
constexpr T* Vector<T>::arr() const noexcept
{
    return m_arr;
}


template <typename T>
T* Vector<T>::operator->() const 
{
    return m_arr;
}

#endif