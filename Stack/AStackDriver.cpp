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
//
//****************************************************************************************************

#include <iostream>
#include "AStack.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

template <typename TYPE>
void display(AStack<TYPE>& s);

//****************************************************************************************************

int main()
{
	AStack<int> s;
	int temp;

	cout << "After declaring a stack:" << endl << "Is it empty? ";

	if (s.isEmpty()) 
	{
		cout << "Yes" << endl << endl;
	}
	else 
	{
		cout << "No" << endl << endl;
	}

	for (int i = 1; i <= 7; i++) 
	{
		if (!(s.push(i)))
		{
			cout << "Something went wrong!" << endl;
		}
	}

	cout << "The size now: " << s.getSize() << endl << endl;
	cout << "Display stack the first time: ";

	display(s);

	cout << "Display stack again: ";

	display(s);

	cout << "Is it full? ";

	if (s.isFull()) 
	{
		cout << "Yes" << endl << endl;
	}
	else 
	{
		cout << "No" << endl << endl;
	}

	cout << "Pop the first three out" << endl;

	s.pop(temp);

	cout << "First pop out: " << temp << endl;

	s.pop(temp);

	cout << "Second pop out: " << temp << endl;

	s.pop(temp);

	cout << "Third pop out: " << temp << endl;
	cout << "Now we have: ";

	display(s);

	cout << "Is it empty now? ";

	if (s.isEmpty())
	{
		cout << "Yes";
	}
	else 
	{
		cout << "No";
	}
}

//****************************************************************************************************

template <typename TYPE>
void display(AStack<TYPE>& s) 
{
	AStack<int> anotherS;
	int temp;
	int size = s.getSize();

	for (int i = 0; i < size; i++) 
	{
		s.pop(temp);

		anotherS.push(temp);

		cout << temp << " ";
	}

	for (int i = 0; i < size; i++)
	{
		anotherS.pop(temp);

		s.push(temp);
	}

	for (int i = 0; i < size; i++)
	{
		s.pop(temp);

		anotherS.push(temp);
	}

	for (int i = 0; i < size; i++)
	{
		anotherS.pop(temp);

		s.push(temp);
	}

	cout << endl << endl;
}

/*
After declaring a stack:
Is it empty? Yes

The size now: 7

Display stack the first time: 7 6 5 4 3 2 1

Display stack again: 7 6 5 4 3 2 1

Is it full? No

Pop the first three out
First pop out: 7
Second pop out: 6
Third pop out: 5
Now we have: 4 3 2 1

Is it empty now? No
*/