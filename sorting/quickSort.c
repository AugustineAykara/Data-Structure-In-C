#include<stdio.h>


void quickSort(int arr[], int first, int last)
{
	int i, j, pivot, temp;

	if (first < last)
	{
		pivot = arr[first];
		i = first;
		j = last;

		while(i < j)
		{
			while(arr[i] <= pivot && i < last)
			{
				i++;
			}
			while(arr[j] > pivot && j > first)
			{
				j--;
			}
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[first];
		arr[first] = arr[j];
		arr[j] = temp;

		quickSort(arr, first, j-1);
		quickSort(arr, j+1, last);
	}
}


void main()
{
	int size, i, arr[10];

	printf("\n Enter the size of array : ");
	scanf("%d", &size);

	printf("\n Enter the array elements : ");
	for(i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, size-1);

	printf("\n After sorting...");
	for (i=0; i<size; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}