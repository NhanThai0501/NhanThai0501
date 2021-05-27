#pragma once
#ifndef MATHSTACK_H
#define MATHSTACK_H
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

#include "IntStack.h"

using namespace std;

class MathStack : public IntStack
{
public:
	// Constructor
	MathStack(int s) : IntStack(s) {}

	// MathStack operations
	void add();
	void sub();
	void multiply();
	void division();
	void addAll();
	void multiplyAll();
};

// PreCondition: NA
// PostCondition: calculate the addition from first two values that being pop off the stack and push them back
void MathStack::add()
{
	int num, sum;

	// Pop the first two values off the stack.
	pop(sum);
	pop(num);

	// Add the two values, store in sum.
	sum += num;

	// Push sum back onto the stack.
	push(sum);
}


// PreCondition: NA
// PostCondition: calculate the difference from first two values that being pop off the stack and push them back
void MathStack::sub()
{
	int num, diff;

	// Pop the first two values off the stack
	pop(diff);
	pop(num);

	// Subtract num from diff
	diff -= num;

	// Push diff back onto the stack
	push(diff);
}

// PreCondition: NA
// PostCondition: calculate the multiplication from first two values that being pop off the stack and push them back
void MathStack::multiply()
{
	int mult, num1;

	// Pop the first two values off the stack
	pop(mult);
	pop(num1);

	// multiply them
	mult *= num1;

	// Push it back onto the stack
	push(mult);
}

// PreCondition: NA
// PostCondition: calculate the division from first two values that being pop off the stack and push them back
void MathStack::division()
{
	int quotient, div;

	// Pop the first two values off the stack
	pop(quotient);
	pop(div);

	// divide them
	quotient = quotient / div;

	// Push it back onto the stack
	push(quotient);
}

// PreCondition: NA
// PostCondition: add all the value after it being pop from the stack and push them back
void MathStack::addAll()
{
	int sum = 0;
	int num;
	while (!isEmpty())
	{
		pop(num);
		sum += num;
	}
	push(sum);
}

// PreCondition: NA
// PostCondition: multiply all the value after it being pop from the stack and push them back
void MathStack::multiplyAll()
{
	int mult = 1;
	int num;
	while (!isEmpty())
	{
		pop(num);
		mult *= num;
	}
	push(mult);
}
#endif
