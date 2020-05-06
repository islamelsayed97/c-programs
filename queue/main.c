#include <stdio.h>
#include "Queue.h"

void display(queueEntry value)
{
    printf("%d\n",value);
}

int main()
{
    char ch,choice;
    Queue q;
    queueEntry value;
    Queue_Init(&q);

    do
    {
        printf("\nEnter the Value: ");
        scanf("%d",&value);
        if(Queue_Append(value, &q) == OK)
        {
            printf("The value was Appended successfully\n");
        }
        else
        {
            printf("Error the queue is Full\n");
            break;
        }
        printf("Do you want to append another element?(y/n): ");
        scanf(" %c", &ch);
    }while (ch == 'y' || ch == 'Y');

    do
    {
        printf("\n\npress...\n\t1) To append another element.\n\t2) To serve an element.\n\t3) To Print the queue size.\
        \n\t4) To display the queue.\n\t5) To clear the queue.\n\t0) To Exit.\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            break;
        case 1:
            printf("\n\nEnter the Value: ");
            scanf("%d",&value);
            if(Queue_Append(value , &q) == OK)
            {
                printf("\n%d was appended successfully\n",value);
            }
            else
            {
                printf("\nError the queue is Full\n");
            }
            break;
        case 2:
            if(Queue_Serve(&value, &q) == OK)
            {
                printf("\n%d was served successfully\n",value);
            }
            else
            {
                printf("\nError! the queue is Empty, there are no elements to serve.\n");
            }
            break;
        case 3:
            printf("\n\nthe size of queue = %d\n",Queue_Size(&q));
            break;
        case 4:
            printf("\n\n");
            if(Queue_Traverse(&q,&display) == OK)
            {
                //nothing
            }
            else
            {
                printf("the queue is Empty, there are no elements to display.\n");
            }
            break;
        case 5:
            Queue_Clear(&q);
            printf("\n\nThe queue was cleared\n");
            break;
        default:
            printf("\n\nWrong choice Please try again\n");
        }
    }while (choice != 0);
    return 0;
}
