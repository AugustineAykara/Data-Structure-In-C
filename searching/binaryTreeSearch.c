/*code written in C*/
/*To search elements in a binary search tree*/
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *lc, *rc;
}*root = NULL;

struct node *createNode(int item)
{
	struct node *n;
	n = (struct node *) malloc (sizeof(struct node));	

	n -> data = item;
	n -> rc = NULL;
	n -> lc = NULL;

	return n;
}

void inorder(struct node *r)
{
	struct node *ptr;
	ptr = r;

	if(ptr != NULL)
	{
		inorder(ptr -> lc);
		printf(" %d ", ptr -> data);
		inorder(ptr -> rc);	
	}
	
}
void preorder(struct node *r)
{
	struct node *ptr;
	ptr = r;

	if(ptr != NULL)
	{
		printf(" %d ", ptr -> data);
		preorder(ptr -> lc);
		preorder(ptr -> rc);	
	}
	
}
void postorder(struct node *r)
{
	struct node *ptr;
	ptr = r;

	if(ptr != NULL)
	{
		postorder(ptr -> lc);
		postorder(ptr -> rc);	
		printf(" %d ", ptr -> data);
	}
	
}

void insertion()
{
	int item, flag = 0;
	struct node *ptr, *parent, *n; 
	printf("\n Enter your item to be inserted : ");
	scanf("%d", &item);

	n = createNode(item);	

	if(root == NULL)
	{
		root = n;
	}
	else 
	{
		ptr = root;
		while (ptr != NULL && flag != 1)
		{
			if(ptr -> data < n -> data)
			{
				parent = ptr;
				ptr = ptr -> rc;			
			}
			else if(ptr -> data > n -> data)
			{
				parent = ptr;
				ptr = ptr -> lc;		
			}
			else
			{
				flag = 1;
				printf("\n ITEM ALREADY EXIST !!!!!!  :) ");
				break;	
			}
		}

		if(flag != 1)
		{
			if(parent  -> data < n-> data)	
			{	
				parent -> rc = n;			
			}
			else
			{
				parent -> lc = n;
			}
		}
	}

	printf("Inorder:");
	inorder(root);
	printf("\n");
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
	printf("\n");
}

void main()
{
	int ch;
	while(1)
	{
		printf("\n 1.INSERT \n 2.SEARCH \n 3.EXIT");
		printf("\n Enter your choice : ");
		scanf("%d", &ch);	
		switch(ch)
		{
			case 1: insertion();
				break;
			//case 2: search();
			//	break;
			case 3: exit(0);
				break;
			default : printf("\n INVALID CHOICE !!!!  ;( ");		
		}
	}	
	
}
