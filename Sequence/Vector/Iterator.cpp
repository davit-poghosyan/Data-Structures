#include "Vector.h"
#include <iostream>
template <typename T>
constexpr Own::Vector<T>::Iterator::Iterator()
{
    m_ptr = nullptr;
}

template <typename T>
constexpr Own::Vector<T>::Iterator::Iterator(T* ptr)
{   
    m_ptr = ptr;
}

template <typename T>
Own::Vector<T>::Iterator::~Iterator() 
{}

template <typename T>
constexpr typename Own::Vector<T>::Iterator& Own::Vector<T>::Iterator::operator++()
{
    ++m_ptr;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::Iterator::operator++(int)
{
    Iterator tmp = *this;
    ++m_ptr;
    return tmp;
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator& Own::Vector<T>::Iterator::operator--()
{
    if (m_ptr)
        --m_ptr;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::Iterator::operator--(int)
{
    Iterator tmp = *this;
    --m_ptr;
    return tmp;
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::Iterator::operator+(std::size_t val)
{
        return Iterator(m_ptr + val);
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator Own::Vector<T>::Iterator::operator-(std::size_t val)
{
    return Iterator(m_ptr - val);
}

template <typename T>
constexpr bool Own::Vector<T>::Iterator::operator==(const Iterator& iter) const
{
    return (this->m_ptr == iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Iterator::operator!=(const Iterator& iter) const
{
    return !(this->m_ptr == iter.m_ptr); 
}


template <typename T>
constexpr bool Own::Vector<T>::Iterator::operator>(const Iterator& iter) const
{
    return (this->m_ptr > iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Iterator::operator<(const Iterator& iter) const
{
    return (this->m_ptr < iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Iterator::operator>=(const Iterator& iter) const
{
    return (this->m_ptr >= iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Iterator::operator<=(const Iterator& iter) const
{
    return (this->m_ptr <= iter.m_ptr); 
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator& Own::Vector<T>::Iterator::operator+=(std::size_t val)
{
    m_ptr+= val;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Iterator& Own::Vector<T>::Iterator::operator-=(std::size_t val)
{
    m_ptr-= val;
    return *this;
}

template <typename T>
constexpr T& Own::Vector<T>::Iterator::operator*()
{
    return *m_ptr;
}

template <typename T>
constexpr const T& Own::Vector<T>::Iterator::operator*() const
{
    return *m_ptr;
}




