#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

void possibleSol(int a,int b,int c)
{
	if(a<b)
	{
		int temp = a;
		a = b;
		b = a;
	}
	if(c > a)
		printf("No\n");

	if((c % gcd(a,b)) != 0)
		printf("No\n");
	else
		printf("Yes\n");
}

int main()
{
	int a,b,c;
	printf("Enter Jug 1 Capacity\n");
	scanf("%d",&a);
	printf("Enter Jug 2 Capacity\n");
	scanf("%d",&b);
	printf("Enter Capacity\n");
	scanf("%d",&c);

	possibleSol(a,b,c);
}