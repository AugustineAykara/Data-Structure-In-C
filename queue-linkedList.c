#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *addr;
}*rear = NULL, *front = NULL;


void insertQueue()
{
	int item;
	struct node *n;
	n =(struct node *) malloc (sizeof(struct node));

	printf("\n Enter the item to be inserted : ");
	scanf("%d", &item);

	n -> data = item;
	n -> addr =NULL;

	if (front == NULL)
	{
		rear = front = n;
	}
	else
	{
		rear -> addr = n;
		rear = n;
	}
}


void deleteQueue()
{
	if (front == NULL)
	{
		printf("\n QUEUE UNDERFLOW !!!");
	}
	else
	{
		printf("\n Element %d has been deleted from the queue  ", front -> data);
		front = front -> addr;
	}
}


void display()
{
	struct node *temp;
	ptr = front; 
	if (ptr == NULL)
	{
		printf("\n LIST IS EMPTY NOW!!!");
	}
	else
	{
		printf("\n");
		while(ptr != NULL)
		{
			printf("  %d  <-", temp -> data);
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
		printf("\n 1. INSERT to Queue \n 2. DELETE from Queue \n 3. DISPLAY \n 4. EXIT ");
		printf("\n Enter your choice : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
					insertQueue();
					display();
					break;
			case 2: 
					deleteQueue();
					display();
					break;
			case 3: 
					display();
					break;
			case 4: 
					exit(0);
					break;
			default:
					printf("\n !!! INVALID CHOICE !!!"); 
		}
	}
}