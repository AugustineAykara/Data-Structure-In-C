#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int c;
	int e;
	struct node *addr;
}*head = NULL;


void traversal(struct node *h)
{
	struct node *ptr;
	ptr = h;

	while(ptr != NULL)
	{
		printf(" %dx^%d +", ptr -> c, ptr -> e);
		ptr = ptr-> addr;
	}
	printf("\n\n");
}

	
struct node * createNode(int coeff, int exp)
{
	struct node *nd;
	nd = (struct node *) malloc (sizeof(struct node));

	nd -> c = coeff;
	nd -> e = exp;
	nd -> addr = NULL;

	return nd;
}		


void createPoly(int n)
{
	int coeff, exp;
	struct node *ptr, *nd;
	// head = createNode(0,0);

	for (int i = 0; i < n; ++i)
	{
		printf("\n Enter the coefficient : ");
		scanf("%d", &coeff);
		printf(" Enter the exponent : ");
		scanf("%d", &exp);

		nd = createNode(coeff, exp);

		if (head == NULL)
		{
			head = nd;
			ptr = nd;
		}
		else
		{
			ptr -> addr = nd;
			ptr = nd;
		}
	}
	printf("\n");
	traversal(head);
}


void main()
{
	int n;
	printf("\n Enter the size of polynomial : ");
	scanf("%d", &n);
	createPoly(n);
	
}