#include<iostream> 
#include<string.h>

using namespace std;

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void lowestCommon(char *x,char *y,int l1,int l2)
{
	int lcs[l1+1][l2+1];
	for(int i=0;i<=l1;i++)
		lcs[i][0] = 0;
	for(int i=0;i<=l2;i++)
		lcs[0][i] = 0;

	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(x[i-1] == y[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else
				lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]);
		}
	}

	int index = lcs[l1][l2];

	char printlcs[index];
	printlcs[index] = '\0';

	int i=l1,j=l2;
	while(i > 0 && j > 0)
	{
		if(x[i-1] == y[j-1])
		{
			printlcs[index-1] = x[i-1];
			index--;
			i--;
			j--;
		}

		if(lcs[i-1][j] > lcs[i][j-1])
			i--;
		else
			j--;
	}
	cout<<printlcs;
}

int main()
{
	char x[] = "AGGTAB";
	char y[] = "GXTXAYB";
	int l1 = strlen(x);
	int l2 = strlen(y);
	lowestCommon(x,y,l1,l2);
}
