#include<stdio.h>


void selectionSort(int arr[], int s)
{
	int i, j, temp;

	for (i=0; i<s; ++i)
	{
		for (j=i+1; j<s; ++j)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
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

	selectionSort(arr, size);
}
