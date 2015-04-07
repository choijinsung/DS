// Lab 009 
// Name : Choi Jinsung
// Student ID : 20123426

#include "lab009.h"


void Graph::Edge(int e1, int e2, int cost)
{ 
	Cost[e1][e2] = cost;
}

void Graph::OutPath(int i)
{ 
	if(i == 0)
	{
		cout << "0 ";
		return;
	}

	OutPath(p[i]);
	 cout << i << " ";
}

void Graph::BellmanFord(int v)
{ 
	for(int i=0; i<numofnodes; i++)
	{
		dist[i] = Cost[v][i];
		p[i] = 0;
	}
	
	p[v] = -1;

	int det = 0;

	do
	{
		det = 0;

		for(int i=0; i<numofnodes; i++)
		{
			if(i == v)
				continue;
			for(int j=0; j<numofnodes; j++)
			{
				if((dist[j] + Cost[j][i]) < dist[i])
				{
					dist[i] = dist[j] + Cost[j][i];
					p[i] = j;
					det = 1;
				}
			}
		}
	}while(det);
}


