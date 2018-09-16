
#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;
	struct node *addr;
	
} *head = NULL;





void traverse()
{
	struct node *ptr;

	if (head  == NULL)
	{
		printf("\n\n List is empty !!!!!!!!\n");
	}
	else
	{
		ptr = head;
		printf(" \n the list elements are :\n");
		while(ptr != NULL)
		{
			printf(" -> %d ", ptr -> data );
			ptr = ptr -> addr;
		}
	}
}



void insertBeg(int value)
{
	struct node *n;
	n = (struct node *) malloc (sizeof(struct node));
	n -> data = value;

	if (head == NULL) 
	{
		head = n;
	}
	else
	{
		n -> addr = head;
		head = n;
	}
	printf("\n element %d successfully postioned at beginning\n", value);

	traverse();
}



void insertRandom(int value, int pos)
{
	int i;
	struct node *n, *ptr, *temp;
	n= (struct node *) malloc (sizeof(struct node));
	n -> data = value;

	ptr = head;
	for(i=1; i<pos; ++i)
	{
		temp = ptr;
		ptr = ptr -> addr;
		if (ptr == NULL)
		{
			printf("\n no such position found!!!\n");
			break;
		}

	}
	temp -> addr = n;
	n -> addr = ptr;
	// n -> addr = ptr -> addr;
	// ptr -> addr = n;

	traverse();
}


void insertEnd(int value)
{
	struct node *n, *ptr;
	n= (struct node *) malloc (sizeof(struct node));
	n -> data = value;
	

	if(head == NULL)
	{
		head = n; 
	}
	else
	{
		ptr = head;
		while(ptr -> addr != NULL)
		{
			ptr = ptr -> addr;
		}
		ptr -> addr = n;
		n -> addr = NULL;
	}

	traverse();
}





void deleteBeg()
{
	struct node *ptr;

	if (head == NULL)
	{
		printf("\n\n List is empty !!!!!!!!\n");
	}
	else
	{
		ptr = head;
		head = ptr -> addr;
		printf("\n\n element %d has been deleted from the beginning\n", ptr -> data);
	}

	traverse();
}



void deleteRandom(int pos)
{
	int i;
	struct node *ptr, *temp;

	if (head == NULL)
	{
		printf("\n\n List is empty !!!!!!!!\n");
	}
	else
	{
		ptr = head;
		for(i=1; i<pos; ++i)
		{
			temp = ptr;
			ptr = ptr -> addr;
			if (ptr == NULL)
			{
				printf("\n no such position found!!!\n");
				break;
			}
		}	
		printf("\n\n element %d has been deleted from the position %d \n", ptr-> data, pos);
		temp -> addr = ptr -> addr;
		// temp = ptr -> addr;
		// ptr -> addr = temp -> addr;
	}

	traverse();
}



void deleteEnd()
{
	struct node *ptr, *temp;
	ptr = head;
	if (ptr -> addr == NULL)
	{
		head = NULL;
		printf("\n\n List is empty !!!!!!!!\n");		
	}
	else
	{
		ptr = head;

		while(ptr -> addr != NULL)
		{
			temp = ptr;
			ptr = ptr -> addr;
		}
		temp -> addr = NULL;
		traverse();
	}
}



void main()
{

	int menuChoice, value, pos;

	// struct node* n = createNode(0);

	while(1)
	{

		printf("\n\n****MENU****\n\n");
		printf(" 1.DISPLAY\n\n 2.INSERT AT BEGINNING\n 3.INSERT AT END\n 4.INSERT AT RANDOM\n\n 5.DELETE FROM BEGINNING\n 6.DELETE FROM END\n 7.DELETE FROM RANDOM\n\n 8.EXIT\n");
		printf("\n Enter your choice : ");
		scanf("%d", &menuChoice);

		switch(menuChoice)
		{
			
			case 1:
					traverse();
					break;

			case 2:
					printf("\n Enter the value to be inserted : ");
					scanf("%d", &value);
					insertBeg(value);
					break;

			case 3:
					printf("\n Enter the value to be inserted : ");
					scanf("%d", &value);
					insertEnd(value);
					break;

			case 4:
					printf("\n Enter the value to be inserted : ");
					scanf("%d", &value);
					printf("\n Enter the position : ");
					scanf("%d", &pos);
					insertRandom(value, pos);
					break;

			case 5:
					deleteBeg();	
					break;

			case 6:
					deleteEnd();	
					break;

			case 7:
					printf("\n Enter the position to be deleted : ");
					scanf("%d", &pos);
					deleteRandom(pos);
					break;

			case 8: 
			        exit(0);

			default :
					printf(" Enter a valid choice\n");

		}
	}
}

