// Lab 007 
// Name : Choi Jinsung
// Student ID : 20123426

#include "lab007.h"


template <class T>
void  MaxLoserTree<T>::BuildLoserTree(const T *externalnode, int n)
{   // initialize the array by using the input
	// Then, compute the internal nodes

    numofelements = n;

	for(int i=0; i<n; i++)
	{
		lt[i] = -1;
		lt[i+n] = externalnode[i];
	}

	for(int i=n; i<2*n; i++)
	{
		int j=i;
		T temp = lt[i], temp2 = 0;

		while(1)
		{
			if(lt[i/2] == -1)
			{
				lt[i/2] = temp;
				break;
			}
			else if(lt[i/2] >= temp)
			{
				temp2 = temp;
				temp = lt[i/2];
				lt[i/2] = temp2;
				i/=2;
			}
			else 
				i/=2;
		}
		i=j;
	}
}


// DO NOT REMOVE THE FOLLOWING
template class MaxLoserTree<int>;


