/* User is at stair 0 and and n no of jump and he have to skip bad step find out maximum steps he can take */ 

#include<stdio.h>

int maxSteps(int maxJump,int badStep)
{
	int count=1,steps=0,temp=badStep;
	while(maxJump>0)
	{
		if(steps+count != badStep)
		{
			steps += count;
			count++;
			maxJump--;
		}
		else
		{
			count++;
			maxJump--;
		}
	}
	count=2;
	temp--;
	int step1=0;
	while(temp>0)
	{
		if(step1+count != badStep)
		{
			step1 += count;
			count++;
			temp--;
		}
		else
		{
			count++;
			temp--;
		}
	}
	if(steps>step1)
		return steps;
	else
		return step1;
}

int main()
{
	int badStep,maxJump;
	printf("Enter Bad Step : ");
	scanf("%d",&badStep);
	printf("Enter Max Jump : ");
	scanf("%d",&maxJump);
	printf("%d\n", maxSteps(maxJump,badStep));
}
