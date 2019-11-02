#include<iostream> 
#include<string.h>

using namespace std;

void findSubset(int a[],int n,int sum)
{
	bool sub[n+1][sum+1];

	for(int i=0;i<=n;i++)
		sub[i][0] = true;
	for(int i=0;i<=sum;i++)
		sub[0][i] = false;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<a[i-1])
				sub[i][j] = sub[i-1][j];
			else
				sub[i][j] = sub[i-1][j] || sub[i-1][j-a[i-1]];
		}
	}
	if(sub[n][sum])
		cout<<"Yes";
	else
		cout<<"No";
}

int main()
{
	int a[] = {6,3,2,1};
	int sum = 5;
	findSubset(a,4,sum);
}