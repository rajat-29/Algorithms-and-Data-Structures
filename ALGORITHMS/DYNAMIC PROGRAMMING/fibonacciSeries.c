#include<stdio.h>

void countStep(int n)
{
	int res[n+1];
	res[0] = 1;
	res[1] = 1;

	for(int i=2;i<=n;i++)
		res[i] = res[i-1] + res[i-2];

	printf("%d\n",res[n]);
}

int main()
{
	int n = 4;
	countStep(n);
}