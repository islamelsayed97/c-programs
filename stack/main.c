#include <stdio.h>
#include "Stack.h"

void display(stackEntry value)
{
    printf("%d\n",value);
}

int main()
{
    char ch;
    stackEntry value,v,choice;
    Stack s;
    Stack_Init(&s);

    do
    {
        printf("\nEnter the Value: ");
        scanf("%d",&value);
        if(Stack_Push(value, &s) == OK)
        {
            printf("The value was pushed successfully\n");
        }
        else
        {
            printf("Error the stack is Full\n");
            break;
        }
        printf("Do you want to push another element?(y/n): ");
        scanf(" %c", &ch);
    }while (ch == 'y' || ch == 'Y');

    do
    {
        printf("\n\npress...\n\t1) To push another element.\n\t2) To pop an element.\n\t3) To Print the stack size.\
        \n\t4) To print the stack top.\n\t5) To display the stack.\n\t6) To clear the stack.\n\t0) To Exit.\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            break;
        case 1:
            printf("\n\nEnter the Value: ");
            scanf("%d",&value);
            if(Stack_Push(value, &s) == OK)
            {
                printf("\n%d was pushed successfully\n",value);
            }
            else
            {
                printf("\nError the stack is Full\n");
            }
            break;
        case 2:
            if(Stack_Pop(&v, &s) == OK)
            {
                printf("\n%d was popped successfully\n",v);
            }
            else
            {
                printf("\nError! the stack is Empty\n");
            }
            break;
        case 3:
            printf("\n\nthe size of stack = %d\n",Stack_Size(&s));
            break;
        case 4:
            if(Stack_Top(&v,&s) == OK)
            {
                printf("\n\nthe stack top is %d\n",v);
            }
            else
            {
                printf("\n\nError! the stack is Empty\n");
            }
            break;
        case 5:
            printf("\n\n");
            if(TraverseStack(&s, &display) == OK)
            {
                //nothing
            }
            else
            {
                printf("the stack is Empty\n");
            }
            break;
        case 6:
            Clear_Stack(&s);
            printf("\n\nThe stack was cleared\n");
            break;
        default:
            printf("\n\nWrong choice Please try again\n");
        }
    }while (choice != 0);

    return 0;
}
