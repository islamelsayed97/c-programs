
#ifndef QUEUE_H_
#define QUEUE_H_

typedef int queueEntry;

#define ARRAY       0
#define LINKED_LIST 1

#define QUEUE_METHOD LINKED_LIST

#if QUEUE_METHOD == ARRAY

#define QUEUE_MAX 100

typedef struct q
{
    int Front;
    int Rear;
    int Size;
    queueEntry Entry[QUEUE_MAX];
}Queue;

#elif QUEUE_METHOD == LINKED_LIST

typedef struct queuenode
{
    queueEntry Entry;
    struct queuenode *next;
}queueNode;

typedef struct q
{
    queueNode *Front;
    queueNode *Rear;
    int Size;
}Queue;

#endif // QUEUE_METHOD

typedef enum
{
    NOK=0,
    OK
}enumFuncReturnStat;
enumFuncReturnStat Queue_Init(Queue *);
enumFuncReturnStat Queue_Append(queueEntry , Queue *);
enumFuncReturnStat Queue_Serve(queueEntry *, Queue *);
enumFuncReturnStat Queue_Clear(Queue *);
enumFuncReturnStat Queue_Traverse(Queue *,void (*ptr_Fun)(queueEntry ));
int Queue_Size(Queue *);
int Is_Queue_Full(Queue *);
int Is_Queue_Empty(Queue *);


#endif // QUEUE_H_
