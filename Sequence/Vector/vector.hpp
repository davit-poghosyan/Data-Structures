#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <initializer_list>

template <typename T>
class Vector
{
private:
    size_t m_size;
    size_t m_capacity;
    T* m_arr;
private:
    constexpr void verifySize(size_t size) const;

public:
    constexpr Vector() noexcept;
    constexpr Vector(const Vector&);
    constexpr Vector<T>& operator=(const Vector<T>&);
    constexpr Vector(Vector&&) noexcept;
    constexpr Vector<T>& operator=(Vector&&) noexcept;
    constexpr Vector(std::initializer_list<T>);
    ~Vector();

    constexpr T& operator[](size_t) const;
    constexpr T& at(size_t) const;
    constexpr T& front() const;
    constexpr T& back() const;

    constexpr bool empty() const noexcept;
    constexpr void resize(size_t);
    constexpr void shrink_to_fit();

    constexpr void clear() noexcept;
    constexpr void insert(size_t pos, const T&);
    constexpr void push_back(const T&);
    constexpr void pop_back();



    T* operator->() const;


    constexpr size_t size() const noexcept;
    constexpr size_t capacity() const noexcept;
    constexpr T* arr() const noexcept;
public:
    constexpr void swap(Vector&) noexcept; 
    void print();
};

#include "vector.tpp"

#endif
   
