
#include "Queue.h"
#include <stdlib.h>

#if QUEUE_METHOD == ARRAY
enumFuncReturnStat Queue_Init(Queue *queue_ptr)
{
    queue_ptr->Front = 0;
    queue_ptr->Rear = -1;
    queue_ptr->Size = 0;
    return OK;
}
enumFuncReturnStat Queue_Append(queueEntry value, Queue *queue_ptr)
{
    if(!Is_Queue_Full(queue_ptr))
    {
        queue_ptr->Rear = (queue_ptr->Rear + 1) % QUEUE_MAX;
        queue_ptr->Entry[queue_ptr->Rear] = value;
        queue_ptr->Size++;
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Queue_Serve(queueEntry *value, Queue *queue_ptr)
{
    if(!Is_Queue_Empty(queue_ptr))
    {
        *value = queue_ptr->Entry[queue_ptr->Front];
        queue_ptr->Front = (queue_ptr->Front + 1) % QUEUE_MAX;
        queue_ptr->Size--;
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Queue_Clear(Queue *queue_ptr)
{
    queue_ptr->Front = 0;
    queue_ptr->Rear = -1;
    queue_ptr->Size = 0;
    return OK;
}
enumFuncReturnStat Queue_Traverse(Queue *queue_ptr,void (*ptr_Fun)(queueEntry ))
{
    if(!Is_Queue_Empty(queue_ptr))
    {
        int i,temp;
        for(i=0,temp=queue_ptr->Front ; i<queue_ptr->Size ; i++)
        {
            ptr_Fun(queue_ptr->Entry[temp]);
            temp = (temp + 1) % QUEUE_MAX;
        }
        return OK;
    }
    else
    {
        return NOK;
    }
}
int Is_Queue_Full(Queue *queue_ptr)
{
    return queue_ptr->Size == QUEUE_MAX;
}
int Is_Queue_Empty(Queue *queue_ptr)
{
    return !queue_ptr->Size;
}
int Queue_Size(Queue *queue_ptr)
{
    return queue_ptr->Size;
}


#elif QUEUE_METHOD == LINKED_LIST


enumFuncReturnStat Queue_Init(Queue *queue_ptr)
{
    queue_ptr->Front = NULL;
    queue_ptr->Rear = NULL;
    queue_ptr->Size = 0;
}
enumFuncReturnStat Queue_Append(queueEntry value, Queue *queue_ptr)
{
    if(!Is_Queue_Full(queue_ptr))
    {
        queueNode *newNode = (queueEntry*)malloc(sizeof(queueEntry));
        newNode->next = NULL;
        newNode->Entry = value;
        if(!Is_Queue_Empty(queue_ptr))
        {
            queue_ptr->Rear->next = newNode;
        }
        else
        {
            queue_ptr->Front = newNode;
        }
        queue_ptr->Rear = newNode;
        queue_ptr->Size++;
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Queue_Serve(queueEntry *value, Queue *queue_ptr)
{
    if(!Is_Queue_Empty(queue_ptr))
    {
        queueNode *temp = queue_ptr->Front;
        *value = temp->Entry;
        queue_ptr->Front = temp->next;

        if(queue_ptr->Front == NULL)
        {
            queue_ptr->Rear = NULL;
        }
        free(temp);
        queue_ptr->Size--;
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Queue_Clear(Queue *queue_ptr)
{
    while(queue_ptr->Front)
    {
        queue_ptr->Rear = queue_ptr->Front->next;
        free(queue_ptr->Front);
        queue_ptr->Front = queue_ptr->Rear;
    }
    queue_ptr->Size = 0;
    return OK;
}
enumFuncReturnStat Queue_Traverse(Queue *queue_ptr,void (*ptr_Fun)(queueEntry ))
{
    if(!Is_Queue_Empty(queue_ptr))
    {
        int i;
        queueNode *temp = queue_ptr->Front;
        for(i=0 ; i<queue_ptr->Size ; i++)
        {
            ptr_Fun(temp->Entry);
            temp = temp->next;
        }
        return OK;
    }
    else
    {
        return NOK;
    }
}
int Queue_Size(Queue *queue_ptr)
{
    return queue_ptr->Size;
}
int Is_Queue_Full(Queue *queue_ptr)
{
    return 0;
}
int Is_Queue_Empty(Queue *queue_ptr)
{
    return !queue_ptr->Front;
}
#endif
