#include <stdio.h>

#define ITERATIVE   0
#define RECURSIVE   1

#define BINARY_SEARCH_METHOD     RECURSIVE

int binarySearch(int, int [], int, int);

int main()
{
    int arr[] = {1,3,4,5,7,12,18,20,26,48,51,55};
    int size = sizeof(arr)/sizeof(arr[0]),target = 55;
    int x = binarySearch(target,arr,0,size-1);
    if(x >= 0)
        printf("number %d is exist in the index %d\n",target,x);
    else
        printf("number %d not found",target);
    return 0;
}

#if BINARY_SEARCH_METHOD == RECURSIVE

int binarySearch(int targetNumber, int arr[], int start , int end)
{
    if(start > end)
        return -1;
    int mid = start + (end - start)/2;
    if(targetNumber == arr[mid])
    {
        return mid;
    }
    else if(targetNumber > arr[mid])
    {
        return binarySearch(targetNumber, arr,mid+1,end);
    }
    else
    {
        return binarySearch(targetNumber, arr, start, mid-1);
    }
}

#elif BINARY_SEARCH_METHOD == ITERATIVE

int binarySearch(int targetNumber, int arr[], int start , int end)
{
    int mid;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(targetNumber == arr[mid])
        {
            return mid;
        }
        else if(targetNumber > arr[mid])
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return -1;
}
#endif
