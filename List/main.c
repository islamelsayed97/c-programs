#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void display(ListEntry value)
{
    printf("%d\n",value);
}

int main()
{
    char ch;
    List myList;
    ListEntry value;

    List_Init(&myList);

    int index=0,choice;
    enumFuncReturnStat fun_return;

    do
    {
        printf("\nEnter the Value: ");
        scanf("%d",&value);
        if(List_Insert(&myList, value , index++) == OK)
        {
            printf("The value was inserted successfully\n");
        }
        else
        {
            printf("Error the List is Full\n");
            break;
        }
        printf("Do you want to insert another element?(y/n): ");
        scanf(" %c", &ch);
    }while (ch == 'y' || ch == 'Y');

     do
    {
        printf("\n\npress...\n\t1) To insert another element.\n\t2) To insert element at the end.\n\t3) To insert element at the beginning.\
               \n\t4) To read an element.\n\t5) To delete an element.\n\t6) To replace an element with a new value.\
               \n\t7) To Print the list size.\n\t8) To display the list.\n\t9) To clear the list.\n\t0) To Exit.\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            break;
        case 1:
            printf("\n\nEnter the Value: ");
            scanf("%d",&value);
            printf("\n\nEnter the index: ");
            scanf("%d",&index);
            fun_return = List_Insert(&myList, value , index);
            if(fun_return == OK)
            {
                printf("\n%d was inserted in index %d successfully\n",value,index);
            }
            else if(fun_return == OUT_OF_RANGE)
            {
                printf("\nError the index is out of range, Note that it mast be in range 0<= index <= size\n");
            }
            else
            {
                printf("\nError the list is full, you can't insert any more elements\n");
            }
            break;
        case 2:
            printf("\n\nEnter the Value: ");
            scanf("%d",&value);
            fun_return = List_Insert(&myList, value , List_Size(&myList));
            if(fun_return == OK)
            {
                printf("\n%d was inserted at the end successfully\n",value);
            }
            else if(fun_return == OUT_OF_RANGE)
            {
                printf("\nError the index is out of range, Note that it mast be in range 0<= index <= size\n");
            }
            else
            {
                printf("\nError the list is full, you can't insert any more elements\n");
            }
            break;
        case 3:
            printf("\n\nEnter the Value: ");
            scanf("%d",&value);
            fun_return = List_Insert(&myList, value , 0);
            if(fun_return == OK)
            {
                printf("\n%d was inserted at the beginning successfully\n",value);
            }
            else if(fun_return == OUT_OF_RANGE)
            {
                printf("\nError the index is out of range, Note that it mast be in range 0<= index <= size\n");
            }
            else
            {
                printf("\nError the list is full, you can't insert any more elements\n");
            }
            break;
        case 4:
            printf("\n\nEnter the index: ");
            scanf("%d",&index);
            fun_return = List_Retrieve(&myList, &value, index );
            if(fun_return == OK)
            {
                printf("\nThe value in index %d = %d\n",index,value);
            }
            else
            {
                printf("\nError the index is out of range, Note that it mast be in range 0<= index <= size\n");
            }
            break;
        case 5:
            printf("\n\nEnter the index: ");
            scanf("%d",&index);
            fun_return = List_Delete(&myList, &value, index );
            if(fun_return == OK)
            {
                printf("\n%d was deleted successfully\n",value);
            }
            else if(fun_return == OUT_OF_RANGE)
            {
                printf("\nError the index is out of range, Note that it mast be in range 0<= index <= size\n");
            }
            else
            {
                printf("\nError! the list is Empty, there are no elements to delete.\n");
            }
            break;
        case 6:
            printf("\n\nEnter the Value: ");
            scanf("%d",&value);
            printf("\n\nEnter the index: ");
            scanf("%d",&index);
            if(List_Replace(&myList, value, index ) == OK)
            {
                printf("\nthe value of index %d now is %d\n",index,value);
            }
            else
            {
                 printf("\nError the index is out of range, Note that it mast be in range 0<= index <= size\n");
            }
            break;
        case 7:
            printf("\n\nthe size of list = %d\n",List_Size(&myList));
            break;
        case 8:
            printf("\n\n");
            if(List_Traverse(&myList,&display) == OK)
            {
                //nothing
            }
            else
            {
                printf("the list is Empty, there are no elements to display.\n");
            }
            break;
        case 9:
            List_Clear(&myList);
            printf("\n\nThe list was cleared, now the list is empty\n");
            break;
        default:
            printf("\n\nWrong choice Please try again\n");
        }
    }while (choice != 0);

    return 0;
}
