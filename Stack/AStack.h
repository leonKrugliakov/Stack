//****************************************************************************************************
//
//      File:                AStack.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #5
//
//      Course Name:         Data Structures I
//
//      Course Number:       COSC 3050 - 10
//
//      Due:                 September 28, 2020
//
//
//      This program creates a stack of integers. Then it populates it with numbers
//		from 1 to 7. Then proceeds to display the whole stack twice. The program
//		also checks to see if the stack is ever full. Then it pops the first three
//		elemets out, then displays the stack and fincally checks if it's empty.
//
//      Other files required:
//			2.	  AStackDriver.cpp - Contains the main and display functions
//
//****************************************************************************************************

#ifndef ASTACK_H
#define ASTACK_H

//****************************************************************************************************

#include <new>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

template<typename TYPE>
class AStack
{
private:
	TYPE* stack;
	int top,
		capacity;
public:
	AStack();
	~AStack();
	bool push(const TYPE& dataIn);
	bool pop(TYPE& dataOut);
	bool peek(TYPE& dataOut) const;
	int getSize() const;
	bool isFull() const;
	bool isEmpty() const;
	bool clearStack();
};

//****************************************************************************************************

template<typename TYPE>
AStack<TYPE>::AStack() 
{
	top = -1;
	capacity = 50;
	stack = new TYPE[capacity];
}

//****************************************************************************************************

template<typename TYPE>
AStack<TYPE>::~AStack() 
{
	delete[] stack;
	stack = nullptr;
}

//****************************************************************************************************

template<typename TYPE>
bool AStack<TYPE>::push(const TYPE& dataIn)
{
	bool success = false;

	top++;
	stack[top] = dataIn;

	if (stack[top] == dataIn)
	{
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool AStack<TYPE>::pop(TYPE& dataOut) 
{
	bool success = false;

	if (top > -1) 
	{
		dataOut = stack[top];
		top--;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool AStack<TYPE>::peek(TYPE& dataOut) const 
{
	bool success = false;

	if (top > -1) 
	{
		success = true;
		dataOut = stack[top];
	}
}

//****************************************************************************************************

template<typename TYPE>
int AStack<TYPE>::getSize() const 
{
	int size = top + 1;

	return size;
}

//****************************************************************************************************

template<typename TYPE>
bool AStack<TYPE>::isFull() const 
{
	bool full = true;

	if (top + 1 < capacity) 
	{
		full = false;
	}

	return full;
}

//****************************************************************************************************

template<typename TYPE>
bool AStack<TYPE>::isEmpty() const 
{
	return (top == -1);
}

//****************************************************************************************************

template<typename TYPE>
bool AStack<TYPE>::clearStack() 
{
	bool success = false;

	while (top > -1) 
	{
		delete stack[top];
		top--;
		success = true;
	}

	return success;
}

//****************************************************************************************************

#endif