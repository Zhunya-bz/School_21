#ifndef CPP_PISCINE_MUTANTSTACK_HPP
#define CPP_PISCINE_MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator; // container_type - это ТИП базового контейнера
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack() : std::stack<T>() {};
    ~MutantStack() {};
    MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
    MutantStack &operator=(const MutantStack &copy) {
        if (this != &copy) {
            std::stack<T>::operator=(copy);
        }
        return *this;
    }

    iterator begin() { // iterator - наш typedef
        return std::stack<T>::c.begin(); // c - базовый контейнер
    }

    iterator end() {
        return std::stack<T>::c.end();
    }

    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }

    const_iterator end() const {
        return std::stack<T>::c.end();
    }

    reverse_iterator rbegin() {
        return std::stack<T>::c.rbegin();
    }

    reverse_iterator rend() {
        return std::stack<T>::c.rend();
    }

    const_reverse_iterator rbegin() const {
        return std::stack<T>::c.rbegin();
    }

    const_reverse_iterator rend() const {
        return std::stack<T>::c.rend();
    }

};


#endif //CPP_PISCINE_MUTANTSTACK_HPP
