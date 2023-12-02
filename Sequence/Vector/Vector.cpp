#include "Vector.h"
#include <iostream>

//=====Member Functions====================================================


template <typename T>
constexpr Own::Vector<T>::Vector() : m_size{}, m_capacity{}, m_arr{nullptr} {}


template <typename T>
constexpr Own::Vector<T>::Vector(std::size_t count) : m_size{count}, m_capacity{count}
{
    m_arr = new T [m_capacity];
    
}

template <typename T>
constexpr Own::Vector<T>::Vector(std::size_t count, const T& value) : m_size{count}, m_capacity{count}
{
    m_arr = new T [m_capacity];
    
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = value;
    }
}

template <typename T>
constexpr Own::Vector<T>::Vector(const Vector& other) : m_size{other.m_size}, m_capacity{other.m_capacity}
{
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = other.m_arr[i];
    }
}

template <typename T> 
constexpr Own::Vector<T>::Vector(Vector&& other) : m_size{other.m_size}, m_capacity{other.m_capacity}, m_arr{other.m_arr}
{
    other.m_size = 0;
    other.m_capacity = 0; 
    other.m_arr = nullptr;
}

template <typename T>
constexpr Own::Vector<T>::Vector(std::initializer_list<T> list) 
{
    m_size = list.size();
    m_capacity = list.size();
    m_arr = new T[m_capacity];

    int i = 0;
    for (const auto& it : list) {
        m_arr[i++] = it;
    }
}

template <typename T>
Own::Vector<T>::~Vector() 
{
    delete[] m_arr;
}


template <typename T>
constexpr Own::Vector<T>& Own::Vector<T>::operator=(const Vector& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_arr = new T[m_capacity];

    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = other.m_arr[i];
    }
    return *this;
}

template <typename T>
constexpr Own::Vector<T>& Own::Vector<T>::operator=(Vector&& other) noexcept
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    delete[] m_arr;
    m_arr = new T[m_capacity];

    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = other.m_arr[i];
    }
    return *this;
}

template <typename T>
constexpr Own::Vector<T>& Own::Vector<T>::operator=(std::initializer_list<T> list) 
{
    delete[] m_arr;

    m_size = list.size();
    m_capacity = list.size();
    m_arr = new T[m_capacity];
    
    int i = 0;
    for (const auto& it : list) {
        m_arr[i++] = it;
    }
}

//=====Element Access======================================================


template <typename T>
constexpr T& Own::Vector<T>::at(std::size_t pos) 
{
    if (m_size != 0 && pos < m_size) {
        return m_arr[pos];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T>
constexpr const T& Own::Vector<T>::at(std::size_t pos) const
{
    if (m_size != 0 && pos < m_size) {
        return m_arr[pos];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T>
constexpr T& Own::Vector<T>::front() {
        return m_arr[0];
}

template <typename T>
constexpr const T& Own::Vector<T>::front() const {
        return m_arr[0];
}

template <typename T>
constexpr T& Own::Vector<T>::back() {
        return m_arr[m_size - 1];
}


template <typename T>
constexpr const T& Own::Vector<T>::back() const {
        return m_arr[m_size - 1];
}

template <typename T>
constexpr T* Own::Vector<T>::data() noexcept {
        return m_arr;
}

template <typename T>
constexpr const T* Own::Vector<T>::data()  const noexcept {
        return m_arr;
}


template <typename T>
T& Own::Vector<T>::operator[](int pos) 
{
    return m_arr[pos];
}


//=====Iterators===========================================================

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::begin() noexcept 
{
    return Iterator(m_arr);    
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Iterator Own::Vector<T>::begin() const noexcept 
{
    return Const_Iterator(m_arr);    
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Iterator Own::Vector<T>::cbegin() const noexcept 
{
    return Const_Iterator(m_arr);    
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::end() noexcept 
{
    return Iterator(m_arr + m_size);    
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Iterator Own::Vector<T>::end() const noexcept 
{
    return Const_Iterator(m_arr + m_size);    
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Iterator Own::Vector<T>::cend() const noexcept 
{
    return Const_Iterator(m_arr + m_size); 
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator Own::Vector<T>::rbegin() noexcept 
{
    return Reverse_Iterator(m_arr + m_size - 1);    
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator Own::Vector<T>::rbegin() const noexcept 
{
    return Const_Reverse_Iterator(m_arr + m_size - 1);    
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator Own::Vector<T>::crbegin() const noexcept 
{
    return Const_Reverse_Iterator(m_arr + m_size - 1);    
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator Own::Vector<T>::rend() noexcept 
{
    return Reverse_Iterator(m_arr - 1);    
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator Own::Vector<T>::rend() const noexcept 
{
    return Const_Reverse_Iterator(m_arr - 1);    
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator Own::Vector<T>::crend() const noexcept 
{
    return Const_Reverse_Iterator(m_arr - 1); 
}

//=====Capacity============================================================

template <typename T>
[[nodiscard]] constexpr bool Own::Vector<T>::empty() const noexcept
{
    return (m_size == 0);
}

template <typename T>
constexpr std::size_t Own::Vector<T>::size() const noexcept
{
    return m_size;
}


template <typename T>
constexpr void Own::Vector<T>::reserve(std::size_t new_cap)
{
    if (m_capacity < new_cap) {
        m_capacity = new_cap;
        T* tmp = new T[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        } 

        delete[] m_arr;  
        m_arr = tmp;
        tmp = nullptr;
    }
}

template <typename T>
constexpr std::size_t Own::Vector<T>::capacity() const noexcept
{
    return m_capacity;
}

template <typename T>
constexpr void Own::Vector<T>::shrink_to_fit()
{
    if (m_capacity != m_size) {
        m_capacity = m_size;
        T* tmp = new T[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        } 

        delete[] m_arr;  
        m_arr = tmp;
        tmp = nullptr;
    }   
}

//=====Modifiers==========================================================

template <typename T>
constexpr void Own::Vector<T>::clear() noexcept
{
    m_size = 0; 
    m_capacity = 0;
    delete[] m_arr;
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::insert(Iterator pos, const T& value)
{
    if (m_size < m_capacity) {
        Own::Vector<T>::Iterator it = this->end();
        while (it != pos) {
            *it = *(it - 1);
            --it; 
        }
        *it = value;
        ++m_size;
        return it;
    }
    else {
        m_capacity = m_capacity * 2;
        T* tmp = new T[m_capacity];
        Own::Vector<T>::Iterator it = this->end();
        
        int i = m_size;
        while (it != pos) {
        tmp[i] = *(it - 1);
        --it; --i; 
        }
        tmp[i] = value;
        --it;
        --i;
        
        Own::Vector<T>::Iterator start = this->begin();
        while (it != start) {
            tmp[i] = *it;
            --it; --i; 
        }

        delete[] m_arr;
        m_arr = tmp;
        tmp = nullptr;
        ++m_size;
        return pos;
    }
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::insert(Iterator pos, T&& value)
{
    this->insert(pos, value);
    return pos;
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::insert(Iterator pos, std::size_t count, const T& value)
{
    if (m_size + count < m_capacity) {
        Own::Vector<T>::Iterator it = this->end() + count - 1;
       
        while (it != pos + count - 1) {
            *it = *(it - count);
            --it; 
        }

        while (it != pos - 1) {
            *it = value;
            --it;
        }
        m_size += count;
        return it;
    } else {
        m_capacity = m_capacity + count;
        T* tmp = new T[m_capacity];
        Own::Vector<T>::Iterator it = this->begin();
        
        int i = 0;
        while (it != pos) {
            tmp[i++] = *it;
            ++it;
        }
        
        int tmp_size = count;
        while (count != 0) {
            tmp[i++] = value;
            --count;
        }

        while (it != this->end()) {
            tmp[i++] = *it;
            ++it;
        }
        
        delete[] m_arr;
        m_arr = tmp;
        tmp = nullptr;
        m_size = m_size + tmp_size;
        return pos;

        
    }
}


template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::insert(Own::Vector<T>::Iterator pos, std::initializer_list<T> ilist)
{
    int ilist_size = ilist.size(); 
    if (m_size + ilist_size < m_capacity) {
        Own::Vector<T>::Iterator it = this->end() + ilist_size - 1;
        while (it != pos + ilist_size - 1) {
            *it = *(it - ilist_size);
            --it; 
        } 

        it -= ilist_size - 1; 
        for (auto val : ilist) {
            *it = val;
            ++it;
        }

        m_size += ilist_size;
        return pos;
    } else {
        m_capacity += ilist_size;
        T* tmp = new T[m_capacity];
        Own::Vector<T>::Iterator it = this->begin();

        int i = 0;
        while (it != pos) {
            tmp[i++] = *it;
            ++it;
        }

        for (auto val : ilist) {
            tmp[i++] = val;
        }

        while (it != this->end()) {
            tmp[i++] = *it;
            ++it;
        }

        delete[] m_arr;
        m_arr = tmp;
        tmp = nullptr;
        m_size += ilist_size;
        return pos;        
    }
}


template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::erase(Own::Vector<T>::Iterator pos)
{   
    if (pos > this->end() || pos < this->begin()) {
        throw std::out_of_range("the position is out of range");
    }
    Own::Vector<T>::Iterator it = pos;
    while (pos != this->end()) {
        *pos = *(pos + 1);
        ++pos;
    }
    --m_size;
    return it;
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::erase(Own::Vector<T>::Iterator start, Own::Vector<T>::Iterator end)
{ 
    if (start > end) {
        throw std::logic_error("the iterator are unconsiderable");
    }
    else if(start > this->end() || end > this->end() || start < this->begin() || end < this->begin()) {
        throw std::out_of_range("position(s) are out of range");
    }

    Own::Vector<T>::Iterator ret = start;
    Own::Vector<T>::Iterator tmp1 = start, tmp2 = end;
    int size = 0;
    while (tmp1 != tmp2) {
        ++tmp1, ++size;
    }
    
    Own::Vector<T>::Iterator result = start;



    while (end != this->end())   {
        *start = *end;
        ++start; ++end;
    }

    m_size -= size;

    return ret;
}

template <typename T>
constexpr void Own::Vector<T>::push_back(const T& value) 
{
    if (m_size < m_capacity) {
        m_arr[m_size] = value;
    } else {
        m_capacity *= 2;
        T* tmp = new T [m_capacity];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        tmp[m_size] = value;
        delete m_arr;
        m_arr = tmp;
        tmp = nullptr;
    }
    ++m_size;
}

template <typename T>
constexpr void Own::Vector<T>::pop_back()
{
    if (m_size == 0) {
        throw std::logic_error("Vector is empty");
    }
    --m_size;
} 