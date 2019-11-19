#include<iostream>
#include<vector>

using namespace std; 

void addEdge(vector<int> V[],int x,int y)
{
	V[x].push_back(y);
	V[y].push_back(x);
}

void printGraph(vector<int> V[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Adjacency list of vertex "<<i<<" head ";
		for(auto x : V[i])
			cout<<"->"<<x;
		cout<<"\n";
	}
}

int main()
{
	int n = 5;
	vector<int> V[n];
	addEdge(V,0,1);
	addEdge(V,0,4);
	addEdge(V,1,2);
	addEdge(V,1,3);
	addEdge(V,1,4);
	addEdge(V,2,3);
	addEdge(V,3,4);
	printGraph(V,n);
}