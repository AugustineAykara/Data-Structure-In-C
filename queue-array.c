#include<stdio.h>
#include<stdlib.h>

int size, item, queue[10], front = -1, rear = -1;


void insertQueue()
{
	int item;
	
	if (rear == size - 1)
	{
		printf("\n QUEUE OVERFLOW !!!\n");
	}
	else
	{
		if (front == -1)
		{
			front = 0;
		}
		printf("\n Enter the item to be inserted : ");
		scanf("%d", &item);
		printf("\n");
		rear++;
		queue[rear] = item;
	}
}


void deleteQueue()
{
	if (front == -1 || front > rear)
	{
		printf("\n QUEUE UNDERFLOW !!!");
	}
	else
	{
		printf("\n Element %d deleted from the Queue ", queue[front]);
		front++;
		if (front > rear)
		{
			front = rear = -1;
		}
	}
	printf("\n");
}


void display()
{
	int i; 

	if (front == -1)
	{
		printf("\n List is empty !!!");
	}
	else
	{
		for (i = front; i<=rear ; ++i)
		{
			printf("  %d <-  ", queue[i]);
		}
	}
	printf("\n");
}


void main()
{
 	int ch, item;
	
	printf("\n Enter the size of the array : ");
	scanf("%d", &size);
	
	while(1)
	{
		printf("\n 1.INSERT to Queue \n 2.DELETE from Queue \n 3.DISPLAY \n 4.EXIT");
		printf("\n Enter your choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: insertQueue();
					display();
					break;
			case 2: deleteQueue();
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