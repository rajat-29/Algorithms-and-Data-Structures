#include<iostream>
using namespace std;

struct tree
{
	int data;
	struct tree *left,*right;
};

struct tree *newNode(int data)
{
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int isMirror(struct tree *s1,struct tree *s2)
{
	if(s1 == NULL && s2 == NULL)
		return true;
	if(s1 == NULL || s2 == NULL)
		return false;

	return s1->data == s2->data && isMirror(s1->left,s2->right) && isMirror(s1->right,s2->left);
}

int main()
{
	tree *a = newNode(1); 
    tree *b = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
  
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 

      isMirror(a, b)? cout << "Yes" : cout << "No";
}