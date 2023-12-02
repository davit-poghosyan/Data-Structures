#include "Vector.h"

template <typename T>
constexpr Own::Vector<T>::Reverse_Iterator::Reverse_Iterator()
{
    m_ptr = nullptr;
}

template <typename T>
constexpr Own::Vector<T>::Reverse_Iterator::Reverse_Iterator(T* ptr)
{   
    m_ptr = ptr;
}

template <typename T>
Own::Vector<T>::Reverse_Iterator::~Reverse_Iterator() 
{}



template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator& Own::Vector<T>::Reverse_Iterator::operator++()
{
    --m_ptr;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator Own::Vector<T>::Reverse_Iterator::operator++(int)
{
    Reverse_Iterator tmp = *this;
    --m_ptr;
    return tmp;
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator& Own::Vector<T>::Reverse_Iterator::operator--()
{
    ++m_ptr;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator Own::Vector<T>::Reverse_Iterator::operator--(int)
{
    Reverse_Iterator tmp = *this;
    ++m_ptr;
    return tmp;
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator Own::Vector<T>::Reverse_Iterator::operator+(std::size_t val)
{
        return Reverse_Iterator(m_ptr - val);
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator Own::Vector<T>::Reverse_Iterator::operator-(std::size_t val)
{
    return Reverse_Iterator(m_ptr + val);
}

template <typename T>
constexpr bool Own::Vector<T>::Reverse_Iterator::operator==(const Reverse_Iterator& iter) const
{
    return (this->m_ptr == iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Reverse_Iterator::operator!=(const Reverse_Iterator& iter) const
{
    return !(this->m_ptr == iter.m_ptr); 
}


template <typename T>
constexpr bool Own::Vector<T>::Reverse_Iterator::operator>(const Reverse_Iterator& iter) const
{
    return (this->m_ptr < iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Reverse_Iterator::operator<(const Reverse_Iterator& iter) const
{
    return (this->m_ptr > iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Reverse_Iterator::operator>=(const Reverse_Iterator& iter) const
{
    return (this->m_ptr <= iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Reverse_Iterator::operator<=(const Reverse_Iterator& iter) const
{
    return (this->m_ptr >= iter.m_ptr); 
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator& Own::Vector<T>::Reverse_Iterator::operator+=(std::size_t val)
{
    m_ptr-= val;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Reverse_Iterator& Own::Vector<T>::Reverse_Iterator::operator-=(std::size_t val)
{
    m_ptr+= val;
    return *this;
}

template <typename T>
constexpr T& Own::Vector<T>::Reverse_Iterator::operator*()
{
    return *m_ptr;
}

template <typename T>
constexpr const T& Own::Vector<T>::Reverse_Iterator::operator*() const
{
    return *m_ptr;
}

