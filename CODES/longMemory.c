#include<stdio.h>

int main()
{
	long a = 12345;
	char *aa=(char*)&a;
	for(int i=0;i<5;i++)
	{
		printf("%p     %x \n", &aa[i],aa[i]);
	}
}