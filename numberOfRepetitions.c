#include <stdio.h>

typedef enum
{
    SEARCH_FIRST,
    SEARCH_LAST
}searchType;

int binarySearch(int, int [], int, searchType);

int main()
{
    int arr[] = {1,5,5,5,7,7,7,7,7,7,9,9,9,9,55}, firstIndex, lastIndex, count, size, target = 7;
    size = sizeof(arr)/sizeof(arr[0]);
    firstIndex = binarySearch(target,arr,size,SEARCH_FIRST);
    if(firstIndex >= 0)
    {
        lastIndex = binarySearch(target,arr,size,SEARCH_LAST);
        count = (lastIndex - firstIndex) + 1;
        printf("number %d is exist %d times\n",target,count);
    }
    else
        printf("number %d not found",target);
    return 0;
}

int binarySearch(int targetNumber, int arr[], int size , searchType type)
{
    int mid, resulat = -1, start = 0, end = size-1;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(targetNumber == arr[mid])
        {
            resulat = mid;
            if(type == SEARCH_FIRST)
                end = mid - 1;
            else
                start = mid+1;
        }
        else if(targetNumber > arr[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    return resulat;
}
