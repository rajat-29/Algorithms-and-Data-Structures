#include <stdio.h> 
#include <stdlib.h>

struct tree
{
	struct tree *left,*right;
	int data;
};

void printGivenLevel(struct tree *head,int level);
int calHeight(struct tree  *head);

void printTree(struct tree *head)
{
	if(head != NULL)
	{
		printTree(head->left);
		printf("%d ",head->data);
		printTree(head->right);
	}
}

void printLevelOrder(struct tree *head)
{
	int h = calHeight(head);
    for(int i=1;i<=h;i++)
    {
      printGivenLevel(head,i);
      printf("\n");
    }
}

void printGivenLevel(struct tree *head,int level)
{
  if(head == NULL)
    return;
  if(level == 1)
  {
      printf("%d ",head->data);
  }
  else
  {
    printGivenLevel(head->left,level-1);
    printGivenLevel(head->right,level-1);
  }
}

int calHeight(struct tree  *head)
{
  if(head == NULL)
    return 0;
  int l = calHeight(head->left);
  int r = calHeight(head->right);
  
  if(l>r)
    return ++l;
  else
    return ++r;
}

struct tree *insert(struct tree *head,int data)
{
	if(head==NULL)
	{
		struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}

	if(data < head->data)
		head->left = insert(head->left,data);
	else if(data > head->data)
		head->right = insert(head->right,data);
}

int main()
{
	struct tree *head;
	head = insert(head,50);
	insert(head,25);
	insert(head,100);
	insert(head,70);
	insert(head,110);
	insert(head,120);
	insert(head,105);
	insert(head,30);
	insert(head,12);
	insert(head,20);
	insert(head,6);
	insert(head,22);
	insert(head,18);
	insert(head,3);
	insert(head,1);
	printf("Normal Tree Print\n");
	printTree(head);
	printf("\n");
	printf("Level Order Traversal is : \n");
	printLevelOrder(head);
}