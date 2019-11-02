#include<stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void knap(int item,int cap,int p[],int w[])
{
	int knap[item+1][cap+1];
	for(int i=0;i<=item;i++)
	{
		for(int j=0;j<=cap;j++)
		{
			if(i==0 || j==0)
				knap[i][j] = 0;
			else if(w[i-1] <= j)
				knap[i][j] = max(knap[i-1][j-w[i-1]] + p[i-1] , knap[i-1][j]);
			else
				knap[i][j] = knap[i-1][j];
		}
	}
	printf("%d\n",knap[item][cap] );

}

int main()
{
	int p[] = {10,12,28};
	int w[] = {1,2,4};
	int c = 6;
	knap(3,c,p,w);
}