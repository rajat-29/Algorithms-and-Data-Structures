#include<stdio.h>

int max(int v[],int n)
{
	int max = v[0];
	for(int i=1;i<n;i++)
	{
		if(v[i] > max)
			max = v[i];
	}
	return max;
}

void lis(int a[],int n)
{
	int val[n];
	val[0] = 1;
	for(int i=1;i<=n;i++)
	{
		val[i] = 1;
		for(int j=0;j<i;j++)
		{
			if(a[i] > a[j] && val[i] < val[j] + 1)
				val[i] = val[j] + 1;
		}
	}
	printf("%d\n", max(val,n));
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    lis( arr, n );  
    return 0; 
}