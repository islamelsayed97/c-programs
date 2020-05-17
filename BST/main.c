#include <stdio.h>
#include "BST.h"

void display(treeEntry data)
{
    printf("%d\t",data);
}

int main()
{
    char ch;
    int choice;
    treeEntry data;
    Tree *root = NULL;
    Tree_Init(root);
    do
    {
        printf("Enter the node value : ");
        scanf("%d",&data);
        Tree_Isert(&root, data);
        printf("Press y to insert another one and any key to exit ");
        scanf(" %c",&ch);
    }while(ch == 'y' || ch == 'Y');

    do
    {
        printf("\n\nPress...\n\t1) To insert another node.\n\t2) To delete a node.\n\t3) To print the tree depth.\
        \n\t4) To print the tree size.\n\t5) To print the Max value in the tree.\n\t6) To print the Min value in the tree.\
        \n\t7) To search in the tree.\n\t8) To clear the tree.\n\t9) To display the tree.\n\t0) To Exit.\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 0:
            break;
        case 1:
            printf("\nEnter the node value : ");
            scanf("%d",&data);
            Tree_Isert(&root, data);
            printf("\n%d is added successfully\n",data);
            break;
        case 2:
            if(isTreeEmpty(root))
            {
                 printf("\nThe tree is empty, there are no elements to delete.\n");
            }
            else
            {
                printf("\nEnter the node value : ");
                scanf("%d",&data);
                Tree_Delete(&root, data);
                printf("\n%d is Deleted successfully\n",data);
            }
            break;
        case 3:
            printf("\nThe tree depth = %d\n",Tree_Depth(root));
            break;
        case 4:
            printf("\nThe tree size = %d\n",Tree_Size(root));
            break;
        case 5:
            if(isTreeEmpty(root))
            {
                printf("\nThe tree is empty.\n");
            }
            else
            {
                printf("\nThe Max value in the tree = %d\n",Tree_Max(root));
            }
            break;
        case 6:
            if(isTreeEmpty(root))
            {
                printf("\nThe tree is empty.\n");
            }
            else
            {
                printf("\nThe Max value in the tree = %d\n",Tree_Min(root));
            }
            break;
        case 7:
            if(isTreeEmpty(root))
            {
                printf("\nThe tree is empty.\n");
            }
            else
            {
                printf("\nEnter the value you want to search about : ");
                scanf("%d",&data);
                if(Tree_Search(root, data))
                    printf("\n%d is exist in the tree\n",data);
                else
                    printf("\n%d is not exist in the tree\n",data);
            }
            break;
        case 8:
            Tree_Clear(&root);
            printf("\nThe tree in cleared\n");
            break;
        case 9:
            if(isTreeEmpty(root))
            {
                printf("\nThe tree is empty, there are no elements to display.\n");
            }
            else
            {
                printf("\n\nPress...\n\t1) To display the tree in in-order mode.\n\t2) To display the tree in pre-order mode.\
                   \n\t3) To display the tree in post-order mode.\nEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    printf("\n");
                    Tree_Traverse(root,&display,IN_ORDER);
                    printf("\n");
                    break;
                case 2:
                    printf("\n");
                    Tree_Traverse(root,&display,PRE_ORDER);
                    printf("\n");
                    break;
                case 3:
                    printf("\n");
                    Tree_Traverse(root,&display,POST_ORDER);
                    printf("\n");
                    break;
                case 4:
                    printf("\n");
                    Tree_Traverse(root,&display,IN_ORDER);
                    printf("\n");
                    break;
                default:
                    printf("\nWrong choice, please try again\n");
                }
            }
            break;
            default:
            printf("\nWrong choice, please try again\n");
        }
    }while(choice != 0);

    return 0;
}
