
#ifndef BST_H_
#define BST_H_

typedef int treeEntry;

typedef struct node
{
    treeEntry data;
    struct node *left,*right;
}Tree;

typedef enum
{
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
}Traverse_Method;

void Tree_Init(Tree *);
void Tree_Clear(Tree **);
int Tree_Size(Tree *);
int Tree_Max(Tree *);
int Tree_Min(Tree *);
int Tree_Depth(Tree *);
int Max(treeEntry, treeEntry);
int isTreeEmpty(Tree *);
Tree *Tree_CreateNewNode(treeEntry);
void Tree_Isert(Tree **, treeEntry);
void Tree_Delete(Tree **, treeEntry);
Tree* Tree_Max_Node(Tree *root);
int Tree_Search(Tree *, treeEntry);
void Tree_Traverse(Tree *, void (*funPtr)(treeEntry), Traverse_Method);

#endif // BST_H_
