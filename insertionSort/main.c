#include <stdio.h>
#include <stdlib.h>

void insertionSort(int [],int );
void printArray(int [], int );

int main()
{
    int arr[] = {80,90,60,50,70,30,10,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printf("The sorted array : ");
    printArray(arr, n);
    return 0;
}
void insertionSort(int arr[],int size)
{
    int i,j,key;
    for(i=1 ; i<size ; i++)
    {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void printArray(int arr[],int size)
{
    int i;
    for(i=0 ; i<size ; i++)
        printf("%d\t",arr[i]);
}
