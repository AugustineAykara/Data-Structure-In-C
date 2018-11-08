#include<stdio.h>


void insertionSort(int arr[], int s)
{
    int i, j, item;

    for (i=1; i<s; ++i)
    {
        item = arr[i];
        j = i-1;
        
        while(item < arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            --j; 
        }
        arr[j+1] = item;
    }
}


void main()
{
    int arr[10], i, size;

    printf("\n Enter the size of array : ");
    scanf("%d", &size);

    printf("\n Enter the array elements : ");
    for (i = 0; i<size; ++i)
    {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, size);

    printf("\n After sorting...");
    for (i=0; i<size; ++i)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}