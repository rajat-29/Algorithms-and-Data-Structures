#include<stdio.h>
#include<limits.h> 

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void cutRod(int a[],int n)
{
	int val[n+1];
	val[0] = 0;
	for(int i=1;i<=n;i++)
	{
		int m = INT_MIN;
		for(int j=0;j<i;j++)
			m = max(m,a[j]+val[i-j-1]);
		val[i] = m;
	}
	printf("%d\n",val[n]);
}

int main()
{
	int arr[] = {3, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    cutRod(arr, size);
    return 0; 
}