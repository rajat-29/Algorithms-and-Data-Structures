#include<iostream>
using namespace std; 

struct tree
{
	int data;
	struct tree *left,*right;
};

void preOrder(struct tree *head)
{
	if(head!=NULL)
	{
		cout<<head->data<<" ";
		preOrder(head->left);
		preOrder(head->right);
	}
}

struct tree *newNode(int data)
{
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct tree *insert(struct tree *head,int a[],int start,int end)
{
	if(start>end)
		return NULL;
		int mid = (start+end)/2;
		struct tree *temp = newNode(a[mid]);
		head = temp;

		head->left = insert(head,a,start,mid-1);
		head->right = insert(head,a,mid+1,end);
	
	return head;
}

int main()
{
	int a[] = {1,2,3,4};
	int n = sizeof(a) / sizeof(a[0]);
	struct tree *head = insert(head,a,0,n);
	preOrder(head);
}