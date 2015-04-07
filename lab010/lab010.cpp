// LAB 010
// Name : Choi Jinsung
// Student ID : 20123426

#include "lab010.h"

template <class T>
void  HeapSort<T>::Adjust(const int root, int n)
{	// adjust binary tree with root "root" to satisfy heap property.
	// The left and right subtrees of "root" already satisfy the heap
	// property. No node index is > n.

	T e = heapArr[root];
	int a = 0;

	for(int i = 2*root; i <= n; i *= 2)
	{
		if(i < n && heapArr[i] > heapArr[i+1])
			i++;
		if(e <= heapArr[i]) 
			break;
		heapArr[i/2] = heapArr[i];
		a = i/2;
	}

	heapArr[a] = e;
}

template <class T>
void  HeapSort<T>::Heapify()
{	// reorder heapArr[1:n] into a heap
	for(int i = hSize/2; i >= 1; i--)
		Adjust(i, hSize);

	for(int i = hSize-1; i >= 1; i--)
	{
		T temp = heapArr[i];
		heapArr[i] = heapArr[i+1];
		heapArr[i+1] = temp;
		Adjust(1,i);
	}
}


// DO NOT REMOVE THE FOLLOWING.
template class HeapSort<int>;

