// HW 3
// Name : Choi Jinsung
// Student ID : 20123426

#include "hw3.h"


template <class T>
void  QuickSort<T>::Swap(int i, int j)
{
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


template <class T>
void  QuickSort<T>::QSort(int s, int e)
{	
	// sort arr[s:e] into nonincreasing order
	cout << "Sort in [" << s << "," << e << "]" << endl;
	Show(s, e);

	if(s >= e)
		return;

	// Implement at the following....

	if(arr[s] <= arr[(s+e)/2])
	{
		if(arr[s] <= arr[e] && arr[e] <= arr[(s+e)/2])
			Swap(s,e);
		else if(arr[(s+e)/2] <= arr[e])
			Swap(s, (s+e)/2);
	}
	else 
	{
		if(arr[e] <= arr[(s+e)/2])
			Swap(s, (s+e)/2);
		else if(arr[(s+e)/2] <= arr[e] && arr[e] <= arr[s])
			Swap(s,e);
	}

	int i = s, j = e + 1;
	T pivot = arr[s];

	do
	{
		do i++; while(arr[i] > pivot);
		do j--; while(arr[j] < pivot);
		if(i < j) 
			Swap(i, j);
	}while(i < j);

	Swap(s, j);

	QSort(s, j - 1);
	QSort(j + 1, e);
}


// DO NOT REMOVE THE FOLLOWING LINE
template class QuickSort<int>;


