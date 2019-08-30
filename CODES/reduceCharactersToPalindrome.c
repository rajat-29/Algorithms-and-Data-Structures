#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void countOperations(char *letter)
{
	int temp = 0;
	//printf("%s\n", letter);
	int len = strlen(letter);
	//printf("%d\n", len);
	int mid = len/2;
	len--;
	for(int i=0;i<mid;i++)
	{
		temp += abs(letter[len] - letter[i]);
		len--;
	}
	printf("%d\n", temp);
}

int main()
{
	char* letter = (char*)malloc(1000);
	printf("Enter string\n");
	scanf("%s",letter);
	//printf("%s\n", letter);
	countOperations(letter);
}