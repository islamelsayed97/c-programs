#include <stdio.h>

int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);

int main()
{
    int (*ptr2fun[4])(int ,int) = {add,sub,mul,div};
    int x,y,z;
    while(1){
        printf("Enter the first number : ");
        scanf("%d",&x);
        printf("Enter the second number : ");
        scanf("%d",&y);
        printf("Press 0) for add, 1) for sub, 2) for mul, 3) for div: ");
        scanf("%d",&z);

        printf("the result = %d\n",ptr2fun[z](x,y));
    }
    return 0;
}

int add(int x, int y)
{
    return (x+y);
}
int sub(int x, int y)
{
    return (x-y);
}
int mul(int x, int y)
{
    return (x*y);
}
int div(int x, int y)
{
    return (x/y);
}
