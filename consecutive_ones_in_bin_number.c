#include <stdio.h>

int main()
{
    int number, count = 0;
    printf("Enter the number: ");
    scanf("%d",&number);

    while (number != 0)
    {
        /*
         * This operation reduces length of every consecutive ones by one
         * x will reach to 0 after the maximum number of consecutive ones is 0
         */
        number = (number & (number << 1));

        count++;
    }
    printf("%d",count);
    return 0;
}

