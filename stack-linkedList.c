#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *addr;
}*top = NULL;


void push()
{
	int item;
	struct node *n;
	n = (struct node *) malloc (sizeof(struct node));

	printf("\n Enter the element to be pushed : ");
	scanf("%d", &item);

	n -> data = item;

	if(top == NULL)
	{
		top = n;
		n -> addr = NULL;
	}
	else
	{
		n -> addr = top;
		top = n;
	}
}


void pop()
{
	if (top == NULL)
	{
		printf("\n STACK UNDERFLOW !!!");
	}
	else
	{
		printf("\n Element %d has been popped out from the stack", top -> data);
		top = top -> addr;
	}
}


void display()
{
	struct node *ptr;
	ptr = top;

	if (top == NULL)
	{
		printf("\n Stack is empty !!!");
	}
	else
	{
		while(ptr != NULL)
		{
			printf("\n -> %d ", ptr -> data);
			ptr = ptr -> addr;
		}
	}
	printf("\n");
}


void main()
{
 	int ch;
	
	while(1)
	{
		printf("\n 1.PUSH to Stack \n 2.POP from Stack \n 3.DISPLAY \n 4.EXIT");
		printf("\n Enter your choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: push();
					display();
					break;
			case 2: pop();
					display();
					break;
			case 3: display();
					break;
			case 4: exit(0);
					break;
			default: printf("\n INVALID CHOICE !!!");
		}
	}
}