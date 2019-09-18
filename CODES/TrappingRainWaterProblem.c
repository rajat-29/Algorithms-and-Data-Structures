#include<stdio.h>
#include<stdlib.h>

int findWater(int arr[],int n)
{
	int result = 0;
	int left_max = 0,right_max = 0;
	int l = 0,h = n-1;
	while(l <= h)
	{
		if(arr[l] < arr[h])
		{
			if(arr[l] > left_max)
				left_max = arr[l];
			else
			{
				result += left_max - arr[l];
				l++;
			}
		}
		else
		{
			if(arr[h] > right_max)
				right_max = arr[h];
			else
			{
				result += right_max - arr[h];
				h--;
			}
		}
	}
	return result; 
}

int main()
{
	int a[] = {3,0,0,2,0,4};
	printf("%d\n", findWater(a,6));
}