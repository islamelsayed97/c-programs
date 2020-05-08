#include <stdio.h>
#include <stdlib.h>
void swap(int *, int *);
void bubbleSort(int arr[], int );
void printArray(int arr[], int );
int main()
{
    int arr[10]={6,4,0,8,3,7,9,5,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
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
void bubbleSort(int arr[], int size)
{
    int i, j;
    for(i=0 ; i<size ; i++)
    {
        for(j=0 ; j<size-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
        // Swap
        swap(&arr[j], &arr[j+1]);
        }
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
