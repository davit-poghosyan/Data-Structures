#include "hashSet.h"
#include "helperFunction.h"

template <typename T>
HashSet<T>::HashSet() : m_elementsCount{0}, m_tableSize{0} {}


template <typename T>
HashSet<T>::HashSet(unsigned int tableSize) : m_elementsCount{0}, m_tableSize{tableSize} {}


template <typename T>
HashSet<T>::HashSet(std::initializer_list<T> list) : m_elementsCount{0}, m_tableSize{static_cast<unsigned int>(list.size())} {
    m_hashTable.resize(m_tableSize);

    for (auto key : list) {
        insert(key);
    }
}



template <typename T>
void HashSet<T>::insert(T key)
{
    if (getLoadFactor() > 0.7) {   
        reHash();
    }

    m_hashTable[hash(key)].push_front(key);
    ++m_elementsCount;
}


template <typename T>
bool HashSet<T>::find(T key)
{
    for (int i = 0; i < m_tableSize; ++i) {
        for (auto it : m_hashTable[i]) {
            if (it == key) {
                return true;
            } 
        }
    }
    return false;
}

template <typename T>
void HashSet<T>::erase(T key)
{
    for (int i = 0; i < m_tableSize; ++i) {
        m_hashTable[i].remove_if([key](const T& value) {
            return value == key;
        });
    }
}



template <typename T>
void HashSet<T>::print()
{
    for (int i = 0; i < m_tableSize; ++i) {
        for (auto it : m_hashTable[i]) {
            std::cout << i << " " << it << std::endl;
        }
    }
}




template <typename T>
unsigned int HashSet<T>::hash(T key)
{
    static const size_t multiplier = 37;
    static const size_t prime = 1000003;

    size_t hash_value = static_cast<size_t>(key);

    hash_value = (hash_value * multiplier) % prime;

    return hash_value % m_tableSize;
}


template <typename T>
void HashSet<T>::reHash()   
{
    if (m_tableSize == 0) {
        m_hashTable.resize(7);
        m_tableSize = 7;
        return;
    }

    std::vector<std::forward_list<T>> tmp(nextTableSize());
    for (int i = 0; i < m_tableSize; ++i) {
         for (auto it : m_hashTable[i]) {
                tmp[hash(it)].push_front(it);
            //tmp[hash(it)].insert(it);
        }
    }

    m_tableSize = nextTableSize();
    m_hashTable = tmp;
}



template <typename T>
double HashSet<T>::getLoadFactor() const
{
    if (m_tableSize == 0) {
        return 1;
    }
    return m_elementsCount / m_tableSize;
}

template <typename T>
unsigned int HashSet<T>::nextTableSize() {
    for (int i = m_tableSize * 2; i > m_tableSize; --i) {
        if (isPrime(i)) {
            return i;
        }
    }
    return 3;
}


int main()
{
    HashSet<int> set{2, 5, 6, 8, 9, 4, 3, 5, 7,8};
    set.print();
}