// HW1
// Name : Choi jinsung
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
	stack[++top] = item;
}

template <class T>
void Stack<T>::Pop()
{
	top--;
}



double PostfixEval(char *ps)
{
	double val = 0;
	double opnd1, opnd2, opnd3;
	int len = strlen(ps);

	Stack<double> est;

	for(int i = 0; i < len; i++)
	{
		if(ps[i] >= '0' && ps[i] <= '9')
		{
			double e = ps[i]-'0';
			est.Push(e);
		}
		else
		{
			opnd2 = est.Top();
			est.Pop();
			opnd1 = est.Top();
			est.Pop();
			
			switch(ps[i])
			{
			case '+':
				opnd3 = opnd1 + opnd2;
				break;
			case '-':
				opnd3 = opnd1 - opnd2;
				break;
			case '*':
				opnd3 = opnd1 * opnd2;
				break;
			case '/':
				opnd3 = opnd1 / opnd2;
				break;
			}
			
			est.Push(opnd3);
		}
	}
	
	val = est.Top();
	return val;
}

void ToPostFix(char *indata, char *postfix)
{
	int len = strlen(indata);

	// now transform the infix into postfix
	Stack<char> pst;

	int i = 0;
	int j = 0;

	for(i = 0; i < len; i++)
	{
		cout << "Token " << indata[i] << endl;
		
		if(indata[i] >= '0' && indata[i] <= '9')
			postfix[j++] = indata[i];
		else
		{
			switch(indata[i])
			{
			case '+': case '-':
				while(pst.Top()!='(' && !(pst.IsEmpty()))
				{
					postfix[j++] = pst.Top();
					pst.Pop();
				}
				pst.Push(indata[i]);
				break;
			case '*': case '/':
				while(pst.Top()!='(' && pst.Top()!='+' && pst.Top()!='-' && !(pst.IsEmpty()))
				{
					postfix[j++] = pst.Top();
					pst.Pop();
				}
				pst.Push(indata[i]);
				break;
			case '(':
				pst.Push(indata[i]);
				break;
			case ')':
				while(pst.Top()!='(' && !(pst.IsEmpty()))
				{
					postfix[j++] = pst.Top();
					pst.Pop();
				}
				pst.Pop();
				break;
			}
		}
		pst.Show();
	}
	while(!(pst.IsEmpty()))
	{
		postfix[j++] = pst.Top();
		pst.Pop();
	}
	postfix[j] = 0;
}




// DO NOT REMOVE THE FOLLOWINGS
template class Stack<double>;

