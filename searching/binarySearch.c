#include<stdio.h>


void binarySearch(int s, int arr[], int num)
{	
	int i, last, first, mid;

	first = 0;
	last = s-1;
	mid = (last + first)/2;

	while(first <= last)
	{
		if (num == arr[mid])
		{
			printf("\n Element found at position : %d", mid+1);
			break;
		}
		else if (num > arr[mid])
		{
			first = mid + 1;
		}
		else if (num < arr[mid])
		{
			last = mid - 1;
		}
		
		mid = (first + last)/2;
	}

	if (first > last)
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

	printf("\n Enter the array elements (ascending order) : ");
	for (i=0; i<size; ++i)
	{
		scanf("%d", &arr[i]);
	}

	printf("\n Enter the element to be searched : ");
	scanf("%d", &num);

	binarySearch(size, arr, num);
}