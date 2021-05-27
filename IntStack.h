#pragma once
#ifndef INTSTACK_H
#define INTSTACK_H

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

class IntStack
{
private:
    int* stackArray;  // Pointer to the stack array
    int stackSize;    // The stack size
    int top;          // Indicates the top of the stack

public:
    // Constructor
    IntStack(int);

    // Copy constructor
    IntStack(const IntStack&);

    // Destructor
    ~IntStack();

    // Stack operations
    void push(int);
    void pop(int&);
    bool isFull() const;
    bool isEmpty() const;
};

// Default constructor                                  
IntStack::IntStack(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

// Copy constructor                             

IntStack::IntStack(const IntStack& obj)
{
    // Create the stack array.
    if (obj.stackSize > 0)
        stackArray = new int[obj.stackSize];
    else
        stackArray = nullptr;

    // Copy the stackSize attribute.
    stackSize = obj.stackSize;

    // Copy the stack contents.
    for (int count = 0; count < stackSize; count++)
        stackArray[count] = obj.stackArray[count];

    // Set the top of the stack.
    top = obj.top;
}

// Destructor                                   
IntStack::~IntStack()
{
    delete[] stackArray;
}

// PreCondition: valid integer 'num'
// PostCondition: push the argument onto the stack
void IntStack::push(int num)
{
    if (isFull())
    {
        cout << "The stack is full.\n";
    }
    else
    {
        top++;
        stackArray[top] = num;
    }
}

// PreCondition: reference valid integer 'num'
// PostCondition: pop the value at the top of the stack off and copies it into the variable passed as an argument.
void IntStack::pop(int& num)
{
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else
    {
        num = stackArray[top];
        top--;
    }
}

// PreCondition: NA
// PostCondition: returns true if the stack is full, or false otherwise.
bool IntStack::isFull() const
{
    bool status;

    if (top == stackSize - 1)
        status = true;
    else
        status = false;

    return status;
}

// PreCondition: NA
// PostCondition: true if the stack is empty, or false otherwise.
bool IntStack::isEmpty() const
{
    bool status;

    if (top == -1)
        status = true;
    else
        status = false;

    return status;
}


#endif 

