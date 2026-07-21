#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <stack>
class RPN
{
private:
    std::stack<char> st;
    std::stack<int> pila;

public:
    class ErrorExeption : public std::exception
    {
        virtual const char *what() const throw();
    };
    RPN(char *input);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
    void calculate();
};

#endif