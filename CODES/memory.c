#include<stdio.h>

int main()
{
	int a = 12345;
	char *aa=(char*)&a;
	for(int i=0;i<4;i++)
	{
		printf("%p     %x \n", &aa[i],aa[i]);
	}
}