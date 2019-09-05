#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int num;
	printf("Enter a Number : ");
	scanf("%d",&num);
	int i=0;
	double sum=0;
	while(num!=0)
	{
		int temp = num&1;
		if(temp == 0)
			sum = sum + pow(2,i);
		i++;
		num = num>>1;
	}
	printf("Compliemt is %f", sum);
}