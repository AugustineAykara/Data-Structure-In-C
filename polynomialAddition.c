
#include<stdio.h>
#include<stdlib.h>

struct node{
	int coeff;
	int exp;
	struct node *addr;
}*head = NULL, *h1 = NULL, *h2 = NULL, *h=NULL;


void traversal(struct node *h)
{
	struct node *ptr;
	ptr = h;

	printf("\n");
	while(ptr != NULL)
	{
		printf("   %d^%d   +", ptr -> coeff, ptr -> exp);
		ptr = ptr -> addr;
	}
	printf("\n\n");
}


struct node * createNode(int c, int e)
{
	struct node *nd;
	nd = (struct node *) malloc (sizeof(struct node));

	nd -> coeff = c;
	nd -> exp = e;
	nd -> addr = NULL;

	return nd;
}


struct node *createPoly(int s)
{
	int i,c,e;
	struct node *nd, *ptr;
	h=NULL;

	for (i = 0; i < s; ++i)
	{
		printf("\n Entre coefficient : ");
		scanf("%d", &c);
		printf(" Enter exponent : ");
		scanf("%d", &e);

		nd = createNode(c,e); 

		if (h == NULL)
		{
			h = nd;
			ptr = nd;
		}
		else
		{
			ptr -> addr = nd;
			ptr = nd;
		}
	}
	traversal(h);
	return h;
}



void polynomialAddition(struct node *p1, struct node *p2)
{
	struct node *add, *ptr;
	add = (struct node *) malloc (sizeof(struct node));

	while(p1 != NULL && p2 != NULL)
	{
		if (p1 -> exp > p2 -> exp)
		{
			add = createNode(p1 -> coeff, p1 -> exp);
			p1 = p1 -> addr;
		}
		else if (p2 -> exp > p1 -> exp)
		{
			add = createNode(p2 -> coeff, p2 -> exp);
			p2 = p2 -> addr;
		}
		else
		{
			add = createNode(p1 -> coeff + p2 -> coeff, p1 -> exp);
			p1 = p1 -> addr;
			p2 = p2 -> addr;
		}

		if (head == NULL)
		{
			head = add;
			ptr = add;
		}
		else
		{
			ptr -> addr = add;
			ptr = add;
		}
	}

	while (p1 != NULL)
	{
		add = createNode(p1 -> coeff, p1 -> exp);
		p1 = p1 -> addr;

		ptr -> addr = add;
		ptr = add;
	}
	while (p2 != NULL)
	{
		add = createNode(p2 -> coeff, p2 -> exp);
		p2 = p2 -> addr;

		ptr -> addr = add;
		ptr = add;
	}
	traversal(head);
}

void main()
{
	int s1,s2;

	printf("\n Enter the size of first polynomial : ");
	scanf("%d", &s1);
	h1 = createPoly(s1);

	printf("\n Enter the size of second polynomial : ");
	scanf("%d", &s2);
	h2 = createPoly(s2);

	polynomialAddition(h1 ,h2);
}

