#include <stdio.h>
#include <stdlib.h>
void swap(int *, int *);
void selectionSort(int arr[], int );
void printArray(int arr[], int );
int main()
{
    int arr[10]={6,4,0,8,3,7,9,5,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
/* Function to swap two numbers */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int size)
{
    int i, j, minIndex;
    for(i=0 ; i<size-1 ; i++)
    {
        minIndex = i;
        for(j=i+1 ; j<size ; j++)
        {
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        // Swap the found minimum element with the first element
        swap(&arr[minIndex], &arr[i]);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for(i=0 ; i<size ; i++)
    {
        printf("%d\t",arr[i]);
    }
}
