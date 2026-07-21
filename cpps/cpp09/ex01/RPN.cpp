#include "RPN.hpp"

RPN::RPN(char *input)
{
    std::stack<char> temp;
    while (*input != '\0')
    {
        if (*input == ' ')
        {
            input++;
            continue;
        }
        temp.push(*input);
        input++;
    }
    while (temp.size())
    {
        st.push(temp.top());
        temp.pop();
    }
}

const char *RPN::ErrorExeption::what() const throw()
{
    return ("Error");
}

RPN::RPN(const RPN &other) : st(other.st) {}

RPN &RPN::operator=(const RPN &other)
{
    this->st = other.st;
    return (*this);
}

RPN::~RPN() {}

void RPN::calculate()
{
    while (!st.empty())
    {
        char c = st.top();
        st.pop();

        if (c >= '0' && c <= '9')
            pila.push(c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (pila.size() < 2)
                throw(RPN::ErrorExeption());
            int second = pila.top();
            pila.pop();
            int first = pila.top();
            pila.pop();
            int res;
            if (c == '+')
                res = first + second;
            else if (c == '-')
                res = first - second;
            else if (c == '*')
                res = first * second;
            else
            {
                if (second == 0)
                    throw(RPN::ErrorExeption());
                res = first / second;
            }
            pila.push(res);
        }
        else
         throw RPN::ErrorExeption();
    }
    if (pila.size() != 1)
        throw(RPN::ErrorExeption());
    std::cout << pila.top() << std::endl;
}