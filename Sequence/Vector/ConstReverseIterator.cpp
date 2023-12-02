#include "Vector.h"

template <typename T>
constexpr Own::Vector<T>::Const_Reverse_Iterator::Const_Reverse_Iterator()
{
    m_ptr = nullptr;
}

template <typename T>
constexpr Own::Vector<T>::Const_Reverse_Iterator::Const_Reverse_Iterator(T* ptr)
{   
    m_ptr = ptr;
}

template <typename T>
Own::Vector<T>::Const_Reverse_Iterator::~Const_Reverse_Iterator() 
{}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator& Own::Vector<T>::Const_Reverse_Iterator::operator++()
{
    --m_ptr;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator Own::Vector<T>::Const_Reverse_Iterator::operator++(int)
{
    Const_Reverse_Iterator tmp = *this;
    --m_ptr;
    return tmp;
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator& Own::Vector<T>::Const_Reverse_Iterator::operator--()
{
    ++m_ptr;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator Own::Vector<T>::Const_Reverse_Iterator::operator--(int)
{
    Const_Reverse_Iterator tmp = *this;
    ++m_ptr;
    return tmp;
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator Own::Vector<T>::Const_Reverse_Iterator::operator+(std::size_t val)
{
        return Const_Reverse_Iterator(m_ptr - val);
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator Own::Vector<T>::Const_Reverse_Iterator::operator-(std::size_t val)
{
    return Const_Reverse_Iterator(m_ptr + val);
}

template <typename T>
constexpr bool Own::Vector<T>::Const_Reverse_Iterator::operator==(const Const_Reverse_Iterator& iter) const
{
    return (this->m_ptr == iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Const_Reverse_Iterator::operator!=(const Const_Reverse_Iterator& iter) const
{
    return !(this->m_ptr == iter.m_ptr); 
}


template <typename T>
constexpr bool Own::Vector<T>::Const_Reverse_Iterator::operator>(const Const_Reverse_Iterator& iter) const
{
    return (this->m_ptr < iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Const_Reverse_Iterator::operator<(const Const_Reverse_Iterator& iter) const
{
    return (this->m_ptr > iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Const_Reverse_Iterator::operator>=(const Const_Reverse_Iterator& iter) const
{
    return (this->m_ptr <= iter.m_ptr); 
}

template <typename T>
constexpr bool Own::Vector<T>::Const_Reverse_Iterator::operator<=(const Const_Reverse_Iterator& iter) const
{
    return (this->m_ptr >= iter.m_ptr); 
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator& Own::Vector<T>::Const_Reverse_Iterator::operator+=(std::size_t val)
{
    m_ptr-= val;
    return *this;
}

template <typename T>
constexpr typename Own::Vector<T>::Const_Reverse_Iterator& Own::Vector<T>::Const_Reverse_Iterator::operator-=(std::size_t val)
{
    m_ptr+= val;
    return *this;
}

template <typename T>
constexpr const T& Own::Vector<T>::Const_Reverse_Iterator::operator*() const
{
    return *m_ptr;
}

