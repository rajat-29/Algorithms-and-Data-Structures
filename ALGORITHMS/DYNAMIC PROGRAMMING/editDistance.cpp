#include<iostream> 
#include<string.h>

using namespace std;

int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}

int min(int a,int b,int c)
{
	return min(min(a,b),c);
}

void editDistance(string s1,string s2,int n,int m)
{
	int editDis[n+1][m+1];

	for(int i=0;i<=n;i++)
		editDis[i][0] = i;
	for(int i=0;i<=m;i++)
		editDis[0][i] = i;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1] == s2[j-1])
				editDis[i][j] = editDis[i-1][j-1];
			else
				editDis[i][j] = 1 + min(editDis[i-1][j],editDis[i][j-1],editDis[i-1][j-1]);
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			printf("%d ",editDis[i][j]);
		printf("\n");
	}
	printf("%d\n",editDis[n][m]);
}

int main()
{
	string s1 = "sunday";
	string s2 = "saturday";
	editDistance(s1,s2,s1.length(),s2.length());
}