// Lab 004 
// Name : Choi Jinsung 
// Student ID : 20123426 

#include "lab004.h"

template <class T> 
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	queue = new T[capacity];
	front = rear = 0;
}


// IMPLEMENT THE FUNCTIONS HERE
template <class T>
bool Queue<T>::IsEmpty() const
{
	return front == rear;
}

template <class T>
bool Queue<T>::IsFull() const
{
	return (rear+1)%capacity==front;
}

template <class T>
void Queue<T>::Push(const T& item)
{
	if(rear==(capacity-1))
	{
		queue[rear]=item;
		rear=0;
	}
	else
		queue[rear++]=item;
}

template <class T>
void Queue<T>::Pop()
{
	if(front==(capacity-1))
		front=0;
	else
		front++;
}

template <class T>
void Queue<T>::Show()
{
	cout << "Queue : ";
	if(front==rear)
		cout << endl;
	else if(front>rear)
	{
		for(int i=front; i<capacity; i++)
			cout << queue[i] << " ";
		for(int i=0; i<rear; i++)
			cout << queue[i] << " ";
		cout << endl;
	}
	else
	{
		for(int i=front; i<rear; i++)
			cout << queue[i] << " ";
		cout << endl;
	}
}
// Do Not Remove the followings
// This is for template instantiation
template class Queue<char>;


