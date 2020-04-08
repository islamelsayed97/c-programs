/*
 * linked_list.c
 *
 *  Created on: Aug 4, 2018
 *      Author: Islam
 */
#include<stdio.h>

/* struct for node elements */
typedef struct node{
    int id;
    struct node *next;
    struct node *prev;
}node;

/* create start and end pointer for linked list */
node *start = NULL;
node *end = NULL;

node *create_node();
void append(node *ele);
void print(node *linked_list);
void delet(int id);
node *search(int id);
void insert(node *ele);
int main()
{
    int no_of_nodes,i,id,input;
    printf("Enter no.of nodes you want to create: ");
    scanf("%d",&no_of_nodes);
    for(i=0 ; i<no_of_nodes ; i++)
    {
        node *ptr = create_node();
        printf("Enter ID of node %d ",i+1);
        scanf("%d",&id);
        ptr->id = id;
        append(ptr);
    }
    do{
        printf("\n\nPress (0) to exit.\nPress (1) to add another node.\nPress (2) to delete node.\nPress (3) to search on node.\n");
        printf("Press (4) to insert node in sorted linked list.\nPress (5) to print the linked list.\nEnter your choice :");
        scanf("%d",&input);
        node *new_node = create_node();
        switch(input){
        case 0:
            return 0;
        case 1:
            printf("\nEnter ID of node : ");
            scanf("%d",&id);
            new_node->id = id;
            append(new_node);
            printf("\n%d is added successfully\n",id);
            break;
        case 2:
            printf("\nEnter ID of node that you want to delete ");
            scanf("%d",&id);
            delet(id);
            break;
        case 3:
            printf("\nEnter ID of node that you want to search on it ");
            scanf("%d",&id);
            if(search(id) != NULL)
            {
                printf("The element is exist\n");
            }
            else
                printf("The element is not exist\n");
            break;
        case 4:
            printf("\nEnter ID of node :");
            scanf("%d",&id);
            new_node->id = id;
            insert(new_node);
            break;
        case 5:
            printf("\n");
            print(start);
            break;
        default:
            printf("Error! wrong choice Try again...");

        }
    }while(input != 0);

    return 0;
}
node *create_node(){
    return ((node*)malloc(sizeof(node)));
}
void append(node *ele)
{
    if(start == NULL)
    {
        start = ele;
        end = ele;
        ele->next = NULL;
        ele->prev = NULL;
    }
    else
    {
        end->next = ele;
        ele->next = NULL;
        ele->prev = end;
        end = ele;
    }
}
void print(node *linked_list)
{
    if(linked_list == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        node *temp = linked_list;
        while(temp != NULL)
        {
            printf("%d",temp->id);
            (temp->next != NULL)? printf(" -> ") : printf("\n");
            temp = temp->next;
        }

    }
}
node *search(int id)
{
    node *temp;
    temp = NULL;
    if(start)
    {
        temp = start;
        while(temp != NULL && temp->id != id)
            temp = temp->next;
    }
    return temp;
}
void delet(int id)
{
    node *temp = search(id);
    if(temp)
    {
        if(temp == start && temp == end)
            start = end = NULL;
        else if(temp == start)
        {
            start = start->next;
            start->prev = NULL;
        }
        else if(temp == end)
        {
            end = end->prev;
            end->next = NULL;
        }
        else
        {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

        }
        printf("\n%d is deleted successfully\n",temp->id);
        free(temp);

     }
     else
     {
        printf("\nError %d is not found in the Linked list\n",id);
     }
}

void insert(node *ele)
{
    node *temp = start;
    while(temp->id < ele->id)
        temp = temp->next;
    if(temp == NULL)
        append(temp);
    else if(temp == start)
    {
        ele->next = start;
        ele->prev = NULL;
        start = ele;
    }
    else{
        temp->prev->next = ele;
        ele->prev = temp->prev;
        ele->next = temp;
        temp->prev = ele;
    }
}
