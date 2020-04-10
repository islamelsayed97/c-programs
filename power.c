#include<stdio.h>
int n_power(int number,int power);

int main()
{
    int number,Power;
    printf("Enter The Number: ");
    scanf("%d",&number);
    printf("Enter The Power: ");
    scanf("%d",&Power);
    printf("%d Power %d = %d",number, Power, n_power(number,Power));
    return 0;
}

int n_power(int number,int power)
{
    if(power > 0)
    {
        return number*n_power(number,power-1);
    }
    else
    {
        return 1;
    }
}
