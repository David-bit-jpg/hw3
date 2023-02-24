#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack():std::vector<T>()
{
}

template <typename T>
Stack<T>::~Stack()
{
    
}

template <typename T>
std::size_t Stack<T>::size() const {
    return std::vector<T>::size();
}

template <typename T>
bool Stack<T>::empty() const {
    return std::vector<T>::size()==0;
}

template <typename T>
void Stack<T>::push(const T& item)
{
    this->push_back(item);
}

template <typename T>
void Stack<T>::pop()
{
    if(empty())
    {
        throw std::underflow_error("Stack empty");
    }
    else
    this->pop_back();
}

template <typename T>
const T& Stack<T>::top() const
{
    if(empty())
    {
        throw std::underflow_error("Stack empty");
    }
    else
    return this->back();
}
#endif