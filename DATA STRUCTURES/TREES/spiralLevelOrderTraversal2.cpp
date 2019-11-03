#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std; 

struct tree 
{
	struct tree *left,*right;
	int data;
};

void printTree(struct tree *head)
{
	if(head != NULL)
	{
		printTree(head->left);
		printf("%d ", head->data);
		printTree(head->right);
	}
}


void printGivenLevel(struct tree *head,int level,bool ltr)
{
  if(head == NULL)
    return;
  if(level == 1)
  {
      printf("%d ",head->data);
  }
  else
  {
    if (ltr) { 
            printGivenLevel(head->left,level-1,ltr);
    		printGivenLevel(head->right,level-1,ltr);
        } 
        else { 
        	printGivenLevel(head->right,level-1,ltr);
            printGivenLevel(head->left,level-1,ltr); 
        } 
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

void printLevelOrder(struct tree *head)
{
	int h = calHeight(head);
	bool dir = false;
    for(int i=1;i<=h;i++)
    {
      printGivenLevel(head,i,dir);
      dir = !dir;
      printf("\n");
    }
}

struct tree *insert(struct tree *head,int data)
{
	if(head == NULL)
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

	return head;
}

int main()
{
	struct tree *head = NULL;
	head = insert(head,10);
	insert(head,7);
	insert(head,15);
	insert(head,1);
	insert(head,9);
	insert(head,12);
	insert(head,17);
	cout<<"Normal Tree Print : \n";
	printTree(head);
	cout<<"Spiral Level Order Tree Print : \n";
	printLevelOrder(head);
}