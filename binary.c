#include <stdio.h>

int main()
{
    int bin_number,decimal_number = 0,base = 1;
    printf("Enter the binary number: ");
    scanf("%d",&bin_number);

    while(bin_number > 0)
    {
        decimal_number += (bin_number%10)*base;
        bin_number /= 10;
        base *= 2;
    }

    printf("The decimal number is %d",decimal_number);

    return 0;
}
