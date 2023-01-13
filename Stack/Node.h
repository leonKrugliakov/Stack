//****************************************************************************************************
//
//      File:                Node.h
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
//		    1.    AStack.h - Contains the Stack class
//			2.	  AStackDriver.cpp - Contains the main and display functions
//
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* next;
	Node();
	Node(TYPE d, Node<TYPE>* n = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(TYPE d, Node<TYPE>* n)
{
	data = d;
	next = n;
}

//****************************************************************************************************

#endif