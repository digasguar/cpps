#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <iostream>
#include <stack>
#include <iterator>
template <class T>
class MutantStack : public std::stack<T>
{
public:
    using std::stack<T>::c;
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return c.begin(); }
    iterator end() { return c.end(); }
};

#endif