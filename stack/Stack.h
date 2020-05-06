
#ifndef STACK_H_
#define STACK_H_

typedef int stackEntry;

#define ARRAY       0
#define LINKED_LIST 1

#define STACK_METHOD ARRAY

#if STACK_METHOD == ARRAY

#define STACK_MAX 100

typedef struct s
{
    int top;
    stackEntry Entry[STACK_MAX];
}Stack;
#elif STACK_METHOD == LINKED_LIST

typedef struct stackNode
{
    stackEntry Entry;
    struct stackNode *next;
}StackNode;

typedef struct s
{
    StackNode *top;
    int Size;
}Stack;

#endif // STACK_METHOD

typedef enum
{
    NOK=0,
    OK,
    False=0,
    True
}enumFuncReturnStat;

enumFuncReturnStat Stack_Init(Stack *);
enumFuncReturnStat Stack_Push(stackEntry , Stack *);
enumFuncReturnStat Stack_Pop(stackEntry *, Stack * );
enumFuncReturnStat Stack_Top(stackEntry *, Stack * );
enumFuncReturnStat Is_Stack_Full(Stack * );
enumFuncReturnStat Is_Stack_Empty(Stack * );
enumFuncReturnStat TraverseStack(Stack *,void (*ptr_Fun)(stackEntry value));
int Stack_Size(Stack *);
void Clear_Stack(Stack *);

#endif // STACK_H_
