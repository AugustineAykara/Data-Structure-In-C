#include<stdio.h>


void bubbleSort(int arr[], int s)
{
	int i, j, temp;

	for (i=0; i<s; ++i)
	{
		for (j=0; j<s-i-1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	printf("\n After sorting...\n");
	for (i=0; i<s; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}


void main()
{
	int arr[10], size, i ,j;

	printf("\n Enter the size of array : ");
	scanf("%d", &size);

	printf("\n Enter the array elements : ");
	for(i=0; i<size; ++i)
	{
		scanf("%d", &arr[i]);
	}

	bubbleSort(arr, size);
}
