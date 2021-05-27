#pragma once
#ifndef MATHSTACKTEMPLATE_H
#define MATHSTACKTEMPLATE_H

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

#include "DynamicStackTemplate.h"

using namespace std;

template <class T>
class MathStackTemplate : public DynamicStackTemplate<T>
{
public:
	// Constructor
	MathStackTemplate() : DynamicStackTemplate<T>() {}

	// MathStackTemplate operations
	void add();
	void sub();
	void multiply();
	void division();
	void addAll();
	void multiplyAll();
};

template <class T>

// PreCondition: NA
// PostCondition: calculate the difference from first two values that being pop off the stack and push them back
void MathStackTemplate<T>::add()
{
	T num, sum;

	// Pop the first two values off the stack.
	DynamicStackTemplate<T>::pop(sum);
	DynamicStackTemplate<T>::pop(num);

	// Add the two values, store in sum.
	sum += num;

	// Push sum back onto the stack.
	DynamicStackTemplate<T>::push(sum);
}

//***********************************************
// Member function sub. sub pops the            *
// first two values off the stack. The          *
// second value is subtracted from the          *
// first value. The difference is pushed        *
// onto the stack.                              *
//***********************************************

// PreCondition: NA
// PostCondition: calculate the difference from first two values that being pop off the stack and push them back
template <class T>
void MathStackTemplate<T>::sub()
{
	T num, diff;

	// Pop the first two values off the stack.
	DynamicStackTemplate<T>::pop(diff);
	DynamicStackTemplate<T>::pop(num);

	// Subtract num from diff.
	diff -= num;

	// Push diff back onto the stack.
	DynamicStackTemplate<T>::push(diff);
}

// PreCondition: NA
// PostCondition: calculate the multiplication from first two values that being pop off the stack and push them back
template <class T>
void MathStackTemplate<T>::multiply()
{
	T mult, num1;
	DynamicStackTemplate<T>::pop(mult);
	DynamicStackTemplate<T>::pop(num1);

	mult *= num1;

	DynamicStackTemplate<T>::push(mult);
}

// PreCondition: NA
// PostCondition: calculate the division from first two values that being pop off the stack and push them back
template <class T>
void MathStackTemplate<T>::division()
{
	T quotient, div;
	DynamicStackTemplate<T>::pop(quotient);
	DynamicStackTemplate<T>::pop(div);

	quotient = quotient / div;

	DynamicStackTemplate<T>::push(quotient);
}

// PreCondition: NA
// PostCondition: add all the value after it being pop from the stack and push them back
template <class T>
void MathStackTemplate<T>::addAll()
{
	T sum = 0.0;
	T num;
	while (!DynamicStackTemplate<T>::isEmpty())
	{
		DynamicStackTemplate<T>::pop(num);
		sum += num;
	}
	DynamicStackTemplate<T>::push(sum);
}

// PreCondition: NA
// PostCondition: multiply all the value after it being pop from the stack and push them back
template <class T>
void MathStackTemplate<T>::multiplyAll()
{
	T mult = 1.0;
	T num;
	while (!DynamicStackTemplate<T>::isEmpty())
	{
		DynamicStackTemplate<T>::pop(num);
		mult *= num;
	}
	DynamicStackTemplate<T>::push(mult);
}
#endif