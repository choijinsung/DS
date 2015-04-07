// HW1
// Name : Choi Jinsung
// Student ID : 20123426

#include "hw1.h"

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity (stackCapacity)
{
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const
{
	return top == -1;
}
	// If number of elements in the stack is 0, return true else return false

template <class T>
inline T & Stack<T>::Top () const
{
	return stack[top];
}


// Return top element of stack

template <class T>
void Stack<T>::Push (const T & item)
{ // Add item to the stack
	stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{
	top--;
}



double PostfixEval(char *ps)
{
	double val = 0;
	int len = strlen(ps);

	Stack<double> est;

	for(int i = 0; i < len; i++)
	{



	}

	return val;
}

void ToPostFix(char *indata, char *postfix)
{
	int len = strlen(indata);

	// now transform the infix into postfix
	Stack<char> pst;

	for(int i = 0; i < len; i++)
	{
		cout << "Token " << indata[i] << endl;









		pst.Show();
	}
}





