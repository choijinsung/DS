// Lab 005
// Name : Choi Jinsung
// Student ID : 20123426

#include "lab005.h"

template <class T>
void CircularList<T>::InsertFront(const T & e)
{// Insert the element e at the front position
	ChainNode<T> *p = new ChainNode<T>();

	if(!Size())
	{
		p -> link = head;
		p -> data = e;
		head -> link = p;
	}			
	else
	{
		p -> link = head -> link;
		p -> data = e;
		head -> link = p;
	}
}


template <class T>
bool CircularList<T>::Delete(const T & e)
{
	// delete an element from the position theIndex
	ChainNode<T> *p = head;
	
	int cnt = 0;

	while(cnt <= Size())
	{
		if(p -> link -> data == e)
		{
			p -> link = p -> link -> link;
			return true;
		}
		p = p -> link;
		++cnt;
	}

	return false;
}



template <class T>
int  CircularList<T>::Size() const 
{
	int cnt = 0;

	ChainNode<T> *p = head -> link;

	while(p != head)
	{
		++cnt;
		p = p -> link;
	}

	return cnt;
}




// DO NOT REMOVE THE FOLLOWINGS. 
template class CircularList<int>;


