#ifndef HASHSET_H
#define HASHSET_H

#include <iostream>
#include <vector>
#include <forward_list>
#include <initializer_list>



template <typename T>
class HashSet
{
static_assert(std::is_integral<T>::value, "MyTemplate can only operate on integral types");

private:
    std::vector<std::forward_list<T>> m_hashTable;
    unsigned int m_elementsCount;
    unsigned int m_tableSize;
private:
    unsigned int hash(T);
    void reHash();
    double getLoadFactor() const;
    unsigned int nextTableSize();
public:
    HashSet();
    explicit HashSet(unsigned int);
    HashSet(std::initializer_list<T>);

    void insert(T);
    bool find(T);
    void erase(T);


    void print();
};


#endif //HASHSET_H