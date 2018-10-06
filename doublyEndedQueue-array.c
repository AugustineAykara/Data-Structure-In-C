#include<stdio.h>
#include<stdlib.h>


int size, front = -1, rear = -1, dequeue[10], item;


void insertQueueRear()
{
	if (rear == size-1)
	{
		printf("\n QUEUE OVERRFLOW !!!");
	}
	else
	{
		if (front == -1)
		{
			front = 0;
		}
		printf("\n Enter the element to be inserted : ");
		scanf("%d", &item);
		rear++;
		dequeue[rear] = item;
	}
}


void insertQueueFront()
{
	if (front == 0)
	{
		printf("\n QUEUE OVERFLOW !!!");
	}
	else 
	{
		if (front == -1)
		{
			front = rear = 0;
		}
		else
		{
			front = front -1;
		}

		printf("\n Enter the element to be inserted : ");
		scanf("%d", &item);
		dequeue[front] = item;
	}
}


void deleteQueueRear()
{
	if (rear == -1)
	{
		printf("\n QUEUE UNDERFLOW !!!");
	}
	else
	{
		printf("\n Element %d has been deleted from the rear", dequeue[rear]);
		rear--;
	}
}


void deleteQueueFront()
{
	if (front == -1 || front > rear) 
	{
		printf("\n QUEUE UNDERFLOW !!!");
	}
	else
	{
		printf("\n Element %d has been deleted from the front", dequeue[front]);
		front++;
		if (front > rear)
		{
			front = rear = -1;
		}
	}
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
		printf("\n");
		for (i = front; i <= rear; ++i)
		{
			printf("  %d <-", dequeue[i]);
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
		printf("\n 1.INSERTION AT FRONT \n 2.INSERTION AT REAR \n 3.DELETION FROM FRONT \n 4.DELTION FROM REAR \n 5.DISPLAY \n 6.EXIT");
		printf("\n Enter your choice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:	insertQueueFront();
					display();
					break;
			case 2: insertQueueRear();
					display();
					break;
			case 3: deleteQueueFront();
					display();
					break;
			case 4: deleteQueueRear();
					display();
					break;
			case 5: display();
					break;
			case 6: exit(0);
					break;
			default: printf("\n INVALID CHOICE !!!");
		}
	}
}