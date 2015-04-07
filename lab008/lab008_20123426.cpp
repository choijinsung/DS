// Lab 008 
// Name : Choi Jinsung
// Student ID : 20123426

#include "lab008.h"

void Graph::Edge(int e1, int e2, int cost)
{ 
	Cost[e1][e2] = cost;
	Cost[e2][e1] = cost;
}

void Graph::Dfs(int vertex)
{ 
	int* arr = new int[numofnodes];
	for(int i=0; i<numofnodes; i++)
		arr[i] = 0;
	
	int index = 0;
	int temp = index;
	int v = vertex;

	visited[v] = 1;
	arr[index++] = v;

	while(temp >= 0)
	{
		for(int i=0; i<numofnodes; i++)
		{
			if(Cost[v][i] && !(visited[i]))
			{
				cout<<v<<"-"<<i<<" : "<<Cost[v][i]<<endl;
				v = i;
				visited[v] = 1;
				arr[index++] = v;
				temp = index;
				break;
			}

			if(i == (numofnodes - 1))
				if(!(Cost[v][i]) || visited[i])
					if(--temp >= 0)
					{
						v = arr[temp];
						break;
					}
		}
	}
}


