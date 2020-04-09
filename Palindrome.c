#include<stdio.h>

int main()
{
    int number,reverse = 0,temp;
    printf("Enter the number: ");
    scanf("%d",&number);
    temp = number;
    while(temp != 0)
    {
        reverse *= 10;
        reverse += temp % 10;
        temp /= 10;
    }
    if(number == reverse)
        printf("%d is a palindrome",number);
    else
        printf("%d is not a palindrome",number);
    return 0;
}
