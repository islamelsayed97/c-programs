#include<stdio.h>

int main()
{
    int decimal_number, bin_number,i, temp;
    printf("Enter an integer in decimal number system : ");
    scanf("%d", &decimal_number);
    printf("%d in binary number system is : ", decimal_number);
    for (i = 31 ; i >= 0 ; i--)
    {
        temp = decimal_number >> i;

        if(temp & 1)
            printf("1");
        else
            printf("0");
    }

    return 0;
}
