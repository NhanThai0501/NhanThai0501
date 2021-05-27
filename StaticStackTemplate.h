#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>

using namespace std;

template <class T>
class StaticStackTemplate
{
private:
    T* array;
    int stackSize;
    int top;

public:
    StaticStackTemplate(int size);

    ~StaticStackTemplate();

    void push(T element);
    void pop(T& element);
    bool isFull() const; // necessary because your stack's static array in fixed-size
    bool isEmpty() const;

    friend ostream& operator<< <>(ostream& out, const StaticStackTemplate<T>& obj);

};

// Argument constructor
template <class T>
StaticStackTemplate<T>::StaticStackTemplate(int size)
{
    array = new T[size];
    stackSize = size;
    top = -1;
}

// Destructor
template <class T>
StaticStackTemplate<T>::~StaticStackTemplate()
{
    delete[] array;
}


// PreCondition: valid T 'item'
// PostCondition: push value onto the stack
template <class T>
void StaticStackTemplate<T>::push(T element)
{
    if (isFull())
        return;
    else
    {
        top++;
        array[top] = element;
    }
}

// PreCondition: reference valid T 'item'
// PostCondition: pop the value at the top of the stack off
template <class T>
void StaticStackTemplate<T>::pop(T& element)
{
    if (isEmpty())
        return;
    else
    {
        element = array[top];
        top--;
    }
}

// PreCondition: NA 
// PostCondition: return true if the stack is empty and false if it's not
template <class T>
bool StaticStackTemplate<T>::isEmpty() const
{
    return top == -1 ? true : false;
}

// PreCondition: NA 
// PostCondition: return true if the stack is full and false if it's not
template <class T>
bool StaticStackTemplate<T>::isFull() const
{
    return top == stackSize - 1 ? true : false;
}

// PreCondition: reference ostream 'out' and valid reference object class T 'obj' of 'StaticStackTemplate' class
// PostCondition: display the elements
template <class T>
ostream& operator<< (ostream& out, const StaticStackTemplate<T>& obj)
{
    for (int i = obj.top; i >= 0; i--)
        out << obj.array[i] << '\n';
    return out;
}
