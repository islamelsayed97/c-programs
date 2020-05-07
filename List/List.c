#include "List.h"
#include <stdlib.h>

#if LIST_METHOD == ARRAY
enumFuncReturnStat List_Init(List *list_ptr)
{
    list_ptr->Size = 0;
}
enumFuncReturnStat List_Insert(List *list_ptr, ListEntry value, int index)
{
    if(!Is_List_Full(list_ptr))
    {
        if(index < list_ptr->Size+1)
        {
            int i;
            for(i=list_ptr->Size ; i>=index ; i--)
            {
                list_ptr->Entry[i+1] = list_ptr->Entry[i];
            }
            list_ptr->Entry[index] = value;
            list_ptr->Size++;
            return OK;
        }
        else
        {
            return OUT_OF_RANGE;
        }
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat List_Retrieve(List *list_ptr, ListEntry *value, int index)
{
    if(index < list_ptr->Size)
    {
        *value = list_ptr->Entry[index];
        return OK;
    }
    else
    {
        return OUT_OF_RANGE;
    }
}
enumFuncReturnStat List_Delete(List *list_ptr, ListEntry *value, int index)
{
    if(!Is_List_Empty(list_ptr))
    {
        if(index < list_ptr->Size)
        {
            *value = list_ptr->Entry[index];
            int i;
            for(i=index ; i<list_ptr->Size ; i++)
            {
                list_ptr->Entry[i] = list_ptr->Entry[i+1];
            }
            list_ptr->Size--;
            return OK;
        }
        else
        {
            return OUT_OF_RANGE;
        }
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat List_Replace(List *list_ptr, ListEntry value, int index)
{
    if(index <= list_ptr->Size)
    {
        list_ptr->Entry[index] = value;
        return OK;
    }
    else
    {
        return OUT_OF_RANGE;
    }
}
enumFuncReturnStat List_Clear(List *list_ptr)
{
    list_ptr->Size = 0;
}
enumFuncReturnStat List_Traverse(List *list_ptr, void (*ptr_Fun)(ListEntry ))
{
    if(!Is_List_Empty(list_ptr))
    {
        int i;
        for(i=0 ; i<list_ptr->Size ; i++)
        {
            ptr_Fun(list_ptr->Entry[i]);
        }
        return OK;
    }
    else
    {
        return NOK;
    }
}
int List_Size(List *list_ptr)
{
    return list_ptr->Size;
}
int Is_List_Empty(List *list_ptr)
{
    return !list_ptr->Size;
}
int Is_List_Full(List *list_ptr)
{
    return (list_ptr->Size == LIST_MAX);
}


#elif LIST_METHOD == LINKED_LIST



enumFuncReturnStat List_Init(List *list_ptr)
{
    list_ptr->head = NULL;
    list_ptr->Size = 0;
    return OK;
}
enumFuncReturnStat List_Insert(List *list_ptr, ListEntry value, int position)
{
    if(!Is_List_Full(list_ptr))
    {
        if(position < list_ptr->Size+1)
        {
            listNode *newNode = (ListEntry*)malloc(sizeof(ListEntry));
            newNode->Entry = value;
            if(position != 0)
            {
                listNode *temp = list_ptr->head;
                int i;
                for(i=0 ; i<position-1 ; i++)
                {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else
            {
                newNode->next = list_ptr->head;
                list_ptr->head = newNode;
            }
            list_ptr->Size++;
            return OK;
        }
        else
        {
            return OUT_OF_RANGE;
        }
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat List_Retrieve(List *list_ptr, ListEntry *value, int position)
{
    if(position < list_ptr->Size)
    {
        listNode *temp = list_ptr->head;
        int i;
        for(i=0 ; i<position ; i++)
        {
            temp = temp->next;
        }
        *value = temp->Entry;
        return OK;
    }
    else
    {
        return OUT_OF_RANGE;
    }
}
enumFuncReturnStat List_Delete(List *list_ptr, ListEntry *value, int position)
{
    if(!Is_List_Empty(list_ptr))
    {
        if(position < list_ptr->Size)
        {
            listNode *temp = list_ptr->head;
            if(position != 0)
            {
                int i;
                for(i=0 ; i<position-1 ; i++)
                {
                    temp = temp->next;
                }
                listNode *temp2 = temp->next;
                temp->next = temp2->next;
                *value = temp2->Entry;
                free(temp2);
            }
            else
            {
               list_ptr->head = temp->next;
               *value = temp->Entry;
               free(temp);
            }
            list_ptr->Size--;
            return OK;
        }
        else
        {
            return OUT_OF_RANGE;
        }
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat List_Replace(List *list_ptr, ListEntry value, int position)
{
        if(position < list_ptr->Size+1)
        {
            listNode *temp = list_ptr->head;
            int i;
            for(i=0 ; i<position ; i++)
            {
                temp = temp->next;
            }
            temp->Entry = value;
            return OK;
        }
        else
        {
            return OUT_OF_RANGE;
        }
}
enumFuncReturnStat List_Clear(List *list_ptr)
{
    listNode *temp;
    while(list_ptr->head)
    {
        temp = list_ptr->head;
        list_ptr->head = temp->next;
        free(temp);
    }
    list_ptr->Size = 0;
    return OK;
}
enumFuncReturnStat List_Traverse(List *list_ptr, void (*ptr_Fun)(ListEntry ))
{
    if(!Is_List_Empty(list_ptr))
    {
        listNode *temp;
        for(temp = list_ptr->head ; temp ; temp = temp->next)
        {
            ptr_Fun(temp->Entry);
        }
        return OK;
    }
    else
    {
        return NOK;
    }
}
int List_Size(List *list_ptr)
{
    return list_ptr->Size;
}
int Is_List_Empty(List *list_ptr)
{
    return !list_ptr->head;
}
int Is_List_Full(List *list_ptr)
{
    return 0;
}

#endif
