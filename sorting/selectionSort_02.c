#include<stdio.h>


void selectionSort(int arr[], int s)
{
	int i, j, min, temp;

	for (i=0; i<s-1; ++i)
	{
		min = i;
		for (j=i+1; j<s; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if(min != i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
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
	selectionSort(arr, size);

	printf("\n After sorting...");
	for (i=0; i<size; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}