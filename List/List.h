#ifndef LIST_H_
#define LIST_H_

typedef int ListEntry;

#define ARRAY           0
#define LINKED_LIST     1

#define LIST_METHOD LINKED_LIST

#if LIST_METHOD == ARRAY
#define LIST_MAX 100

typedef struct l
{
    ListEntry Entry[LIST_MAX];
    int Size;
}List;

#elif LIST_METHOD == LINKED_LIST

typedef struct listnode
{
    ListEntry Entry;
    struct listnode *next;
}listNode;

typedef struct l
{
    listNode* head;
    int Size;
}List;

#endif

typedef enum
{
    NOK=0,
    OK,
    OUT_OF_RANGE
}enumFuncReturnStat;

enumFuncReturnStat List_Init(List *);
enumFuncReturnStat List_Insert(List *, ListEntry , int );
enumFuncReturnStat List_Retrieve(List *, ListEntry *, int );
enumFuncReturnStat List_Delete(List *, ListEntry *, int );
enumFuncReturnStat List_Replace(List *, ListEntry , int );
enumFuncReturnStat List_Clear(List *);
enumFuncReturnStat List_Traverse(List *, void (*ptr_Fun)(ListEntry ));
int List_Size(List *);
int Is_List_Empty(List *);
int Is_List_Full(List *);


#endif // LIST_H_
