
#include "Stack.h"
#include <stdlib.h>

#if STACK_METHOD == ARRAY
enumFuncReturnStat Stack_Init(Stack * Stack_ptr)
{
    Stack_ptr->top = -1;
    return OK;
}
enumFuncReturnStat Stack_Push(stackEntry Value, Stack * Stack_ptr)
{
    if(Is_Stack_Full(Stack_ptr) == False)
    {
        Stack_ptr->Entry[++Stack_ptr->top] = Value;
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Stack_Pop(stackEntry *value_ptr, Stack * Stack_ptr)
{
    if(Is_Stack_Empty(Stack_ptr) == False)
    {
        *value_ptr = Stack_ptr->Entry[Stack_ptr->top--];
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Stack_Top(stackEntry *value_ptr, Stack * Stack_ptr)
{
    if(Is_Stack_Empty(Stack_ptr) == False)
    {
        *value_ptr = Stack_ptr->Entry[Stack_ptr->top];
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Is_Stack_Full(Stack * Stack_ptr)
{
    return (Stack_ptr->top < STACK_MAX-1)? False : True;
}
enumFuncReturnStat Is_Stack_Empty(Stack * Stack_ptr)
{
    return (Stack_ptr->top > -1)? False : True;
}
int Stack_Size(Stack *Stack_ptr)
{
    return (Stack_ptr->top + 1);
}
void Clear_Stack(Stack *Stack_ptr)
{
    Stack_ptr->top = -1;
}
enumFuncReturnStat TraverseStack(Stack *Stack_ptr,void (*ptr_Fun)(stackEntry value))
{
    if(Is_Stack_Empty(Stack_ptr) == False)
    {
        int i;
        for(i=Stack_ptr->top ; i>=0 ; i--)
        {
            ptr_Fun(Stack_ptr->Entry[i]);
        }
        return OK;
    }
    else
    {
        return NOK;
    }
}
#elif STACK_METHOD == LINKED_LIST

enumFuncReturnStat Stack_Init(Stack *stack_ptr)
{
    stack_ptr->top = NULL;
    stack_ptr->Size = 0;
    return OK;
}
enumFuncReturnStat Stack_Push(stackEntry value, Stack *stack_ptr)
{
    if(Is_Stack_Full)
    {
        StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
        newNode->Entry = value;
        newNode->next = stack_ptr->top;
        stack_ptr->top = newNode;
        stack_ptr->Size++;
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Stack_Pop(stackEntry *value, Stack *stack_ptr)
{
    if(Is_Stack_Empty(stack_ptr) == False)
    {
        *value = stack_ptr->top->Entry;
        StackNode *temp = stack_ptr->top;
        stack_ptr->top = stack_ptr->top->next;
        free(temp);
        stack_ptr->Size--;
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Stack_Top(stackEntry *value, Stack *stack_ptr)
{
    if(Is_Stack_Empty(stack_ptr) == False)
    {
        *value = stack_ptr->top->Entry;
        return OK;
    }
    else
    {
        return NOK;
    }
}
enumFuncReturnStat Is_Stack_Full(Stack *stack_ptr)
{
    return NOK;
}
enumFuncReturnStat Is_Stack_Empty(Stack *stack_ptr)
{
    return (stack_ptr->top == NULL)? True : False;
}
int Stack_Size(Stack *stack_ptr)
{
    return stack_ptr->Size;
}
void Clear_Stack(Stack *stack_ptr)
{
    StackNode *temp;
    while( stack_ptr->top != NULL)
    {
        temp = stack_ptr->top;
        stack_ptr->top = temp->next;
        free(temp);
    }
    stack_ptr->Size = 0;
}

enumFuncReturnStat TraverseStack(Stack * stack_ptr, void (*ptr_Fun)(stackEntry ))
{
    if(Is_Stack_Empty(stack_ptr) == False)
    {
        StackNode *temp = stack_ptr->top;
        while(temp)
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
#endif
