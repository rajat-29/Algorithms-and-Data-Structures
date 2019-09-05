#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a,char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

void permuatation(int low,int high,char *num)
{
	//printf("%c\n",num[0] );
	if(low == high)
	{
		int a = atoi(num);
		printf("%d ",a);
		if(a%8 == 0)
			printf("YES \n");
		else
			printf("NO \n");
	}
	else
	{
		for(int i=low;i<=high;i++)
		{
			swap((num+low),(num+i));
			permuatation(low+1,high,num);
			swap((num+low),(num+i));
		}
	}
}

int main()
{
	char num[50];
	printf("Enter Number : ");
	scanf("%s",num);
	int len = strlen(num);
	//printf("%d",len);
	permuatation(0,len-1,num);
}