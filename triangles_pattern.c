#include<stdio.h>

int main()
{
    int height,i,j,k;
    printf("Enter the height: ");
    scanf("%d",&height);

    for(i=0 ; i<=height ; i++)
    {
        for(j=height ; j>i ; j--)
            printf(" ");
        for(k=1 ; k<=i ; k++)
            printf("*");
        printf("\n");

    }
    printf("\n\n");
    for(i=0 ; i<=height ; i++)
    {
        for(j=0 ; j<i ; j++)
            printf(" ");
        for(k=height ; k>i ; k--)
            printf("*");
        printf("\n");

    }

    for(i=0 ; i<=height ; i++)
    {
        for(k=1 ; k<=i ; k++)
            printf("*");
        printf("\n");

    }
    printf("\n\n");
    for(i=0 ; i<=height ; i++)
    {
        for(k=height ; k>i ; k--)
            printf("*");
        printf("\n");

    }
    return 0;
}
