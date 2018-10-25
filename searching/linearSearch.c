#include<stdio.h>


void linearSearch(int s, int arr[], int num)
{
	int i, flag = 0;

	for (i=0; i<s; ++i)
	{
		if (arr[i] == num)
		{
			printf("\n Element found at position %d", i+1);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		printf("\n Element not found :(");
	}
	printf("\n\n");
}


void main()
{
	int i, num, arr[10], size;

	printf("\n Enter the size of array : ");
	scanf("%d", &size);

	printf("\n Enter the array elements : ");
	for (i=0; i<size; ++i)
	{
		scanf("%d", &arr[i]);
	}

	printf("\n Enter the element to be searched : ");
	scanf("%d", &num);

	linearSearch(size, arr, num);
}
