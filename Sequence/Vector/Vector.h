#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept> 
#include <cassert>

namespace Own {
    template <typename T>
    class Vector
    {
    public:  
        class Iterator;
        class Const_Iterator;
        class Reverse_Iterator;
        class Const_Reverse_Iterator;
        private:
            std::size_t m_size;
            std::size_t m_capacity;
            T* m_arr;
        public:
//=====Member Functions=============
            constexpr Vector();
            constexpr Vector(std::size_t count);
            constexpr Vector(std::size_t count, const T& value);
            constexpr Vector(const Vector&);
            constexpr Vector(Vector&&);
            constexpr Vector(std::initializer_list<T>);
            ~Vector();

            constexpr Vector& operator=(const Vector&);
            constexpr Vector& operator=(Vector&&) noexcept;
            constexpr Vector& operator=(std::initializer_list<T>);
//=====Iterators====================
            constexpr Iterator begin() noexcept;
            constexpr Const_Iterator begin() const noexcept;//????????
            constexpr Const_Iterator cbegin() const noexcept;//???????
            
            constexpr Iterator end() noexcept;
            constexpr Const_Iterator end() const noexcept;//????????
            constexpr Const_Iterator cend() const noexcept;//???????

            constexpr Reverse_Iterator rbegin() noexcept;
            constexpr Const_Reverse_Iterator rbegin() const noexcept;//????????
            constexpr Const_Reverse_Iterator crbegin() const noexcept;//???????
            
            constexpr Reverse_Iterator rend() noexcept;
            constexpr Const_Reverse_Iterator rend() const noexcept;//????????
            constexpr Const_Reverse_Iterator crend() const noexcept;//???????

//=====Element Access===============
            constexpr T& at(std::size_t);
            constexpr const T& at(std::size_t) const;
            constexpr T& front();
            constexpr const T& front() const;
            constexpr T& back();
            constexpr const T& back() const;
            constexpr T* data() noexcept;
            constexpr const T* data() const noexcept;
            T& operator[](int);

//=====Capacity=====================
            [[nodiscard]] constexpr bool empty() const noexcept;
            constexpr std::size_t size() const noexcept;
            constexpr void reserve(std::size_t);
            constexpr std::size_t capacity() const noexcept;
            constexpr void shrink_to_fit();
//=====Modifiers====================
            constexpr void clear() noexcept;
            constexpr Iterator insert(Iterator, const T&);
            constexpr Iterator insert(Iterator, T&&);
            constexpr Iterator insert(Iterator, std::size_t, const T&);
            constexpr Iterator insert(Iterator, std::initializer_list<T>);
            
            constexpr Iterator erase(Iterator);
            constexpr Iterator erase(Iterator, Iterator);

            constexpr void push_back(const T&);
            constexpr void pop_back();

//=====Enclosed Iterators===========
        public:
//=====Iterator=====================
            class Iterator {
                private:
                    T* m_ptr;
                public:
                    constexpr Iterator();
                    constexpr Iterator(T*);
                    ~Iterator();
                public:
                    constexpr Iterator& operator++();
                    constexpr Iterator operator++(int);
                    constexpr Iterator& operator--();
                    constexpr Iterator operator--(int);
                    constexpr Iterator operator+(std::size_t);
                    constexpr Iterator operator-(std::size_t);
                    constexpr bool operator==(const Iterator&) const;
                    constexpr bool operator!=(const Iterator&) const;
                    constexpr bool operator>(const Iterator&) const;
                    constexpr bool operator<(const Iterator&) const;
                    constexpr bool operator>=(const Iterator&) const;
                    constexpr bool operator<=(const Iterator&) const; 
                    constexpr Iterator& operator+=(std::size_t);
                    constexpr Iterator& operator-=(std::size_t);

                    constexpr T& operator*();
                    constexpr const T& operator*() const; 
            };
        public:
//=====Const Iterator===============
            class Const_Iterator {
                private:
                    T* m_ptr;
                public:
                    constexpr Const_Iterator();
                    constexpr Const_Iterator(T*);
                    ~Const_Iterator();
                public:
                    constexpr Const_Iterator& operator++();
                    constexpr Const_Iterator operator++(int);
                    constexpr Const_Iterator& operator--();
                    constexpr Const_Iterator operator--(int);
                    constexpr Const_Iterator operator+(std::size_t);
                    constexpr Const_Iterator operator-(std::size_t);
                    constexpr bool operator==(const Const_Iterator&) const;
                    constexpr bool operator!=(const Const_Iterator&) const;
                    constexpr bool operator>(const Const_Iterator&) const;
                    constexpr bool operator<(const Const_Iterator&) const;
                    constexpr bool operator>=(const Const_Iterator&) const;
                    constexpr bool operator<=(const Const_Iterator&) const; 
                    constexpr Const_Iterator& operator+=(std::size_t);
                    constexpr Const_Iterator& operator-=(std::size_t);

                    constexpr const T& operator*() const; 
            };
        public:
//=====Reverse Iterator=============
            class Reverse_Iterator {
                private:
                    T* m_ptr;
                public:
                    constexpr Reverse_Iterator();
                    constexpr Reverse_Iterator(T*);
                    ~Reverse_Iterator();
                public:
                    constexpr Reverse_Iterator& operator++();
                    constexpr Reverse_Iterator operator++(int);
                    constexpr Reverse_Iterator& operator--();
                    constexpr Reverse_Iterator operator--(int);
                    constexpr Reverse_Iterator operator+(std::size_t);
                    constexpr Reverse_Iterator operator-(std::size_t);
                    constexpr bool operator==(const Reverse_Iterator&) const;
                    constexpr bool operator!=(const Reverse_Iterator&) const;
                    constexpr bool operator>(const Reverse_Iterator&) const;
                    constexpr bool operator<(const Reverse_Iterator&) const;
                    constexpr bool operator>=(const Reverse_Iterator&) const;
                    constexpr bool operator<=(const Reverse_Iterator&) const; 
                    constexpr Reverse_Iterator& operator+=(std::size_t);
                    constexpr Reverse_Iterator& operator-=(std::size_t);

                    constexpr T& operator*();
                    constexpr const T& operator*() const; 
            };
//=====Const Reverse Iterator=======
            class Const_Reverse_Iterator {
                private:
                    T* m_ptr;
                public:
                    constexpr Const_Reverse_Iterator();
                    constexpr Const_Reverse_Iterator(T*);
                    ~Const_Reverse_Iterator();
                public:
                    constexpr Const_Reverse_Iterator& operator++();
                    constexpr Const_Reverse_Iterator operator++(int);
                    constexpr Const_Reverse_Iterator& operator--();
                    constexpr Const_Reverse_Iterator operator--(int);
                    constexpr Const_Reverse_Iterator operator+(std::size_t);
                    constexpr Const_Reverse_Iterator operator-(std::size_t);
                    constexpr bool operator==(const Const_Reverse_Iterator&) const;
                    constexpr bool operator!=(const Const_Reverse_Iterator&) const;
                    constexpr bool operator>(const Const_Reverse_Iterator&) const;
                    constexpr bool operator<(const Const_Reverse_Iterator&) const;
                    constexpr bool operator>=(const Const_Reverse_Iterator&) const;
                    constexpr bool operator<=(const Const_Reverse_Iterator&) const; 
                    constexpr Const_Reverse_Iterator& operator+=(std::size_t);
                    constexpr Const_Reverse_Iterator& operator-=(std::size_t);

                    constexpr T& operator*();
                    constexpr const T& operator*() const; 
            };                    
    };
};

#include "Vector.cpp"
#include "Iterator.cpp"
#include "ReverseIterator.cpp"
#include "ConstReverseIterator.cpp"

#endif