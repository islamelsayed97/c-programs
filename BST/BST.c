
#include <stdlib.h>
#include "BST.h"

void Tree_Init(Tree *root)
{
    root = NULL;
}
void Tree_Clear(Tree **root)
{
    if((*root))
    {
        Tree_Clear(&(*root)->left);
        Tree_Clear(&(*root)->right);
        free((*root));
        (*root) = NULL;
    }
}
int Tree_Size(Tree *root)
{
    if(root == NULL)
        return 0;
    return (Tree_Size(root->left) + Tree_Size(root->right)) + 1;
}
int Max(treeEntry num1, treeEntry num2)
{
    return (num1 >= num2)? num1 : num2;
}
int Tree_Depth(Tree *root)
{
    if(root == NULL)
        return -1;
    return Max(Tree_Depth(root->left),Tree_Depth(root->right))+1;
}
int isTreeEmpty(Tree *root)
{
    return !(root);
}
Tree *Tree_CreateNewNode(treeEntry data)
{
    Tree *newNode = (Tree*)malloc(sizeof(Tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void Tree_Isert(Tree **root, treeEntry data)
{
    if(*root == NULL)
    {
        *root = Tree_CreateNewNode(data);
    }
    else if((*root)->data > data)
    {
        Tree_Isert(&(*root)->left, data);
    }
    else
    {
        Tree_Isert(&(*root)->right, data);
    }
}
void Tree_Delete(Tree **root, treeEntry data)
{
    if(*root == NULL)
        return;
    else if (data < (*root)->data)
        Tree_Delete(&(*root)->left,data);
    else if (data > (*root)->data)
        Tree_Delete(&(*root)->right,data);
    else
    {
        if((*root)->left == NULL)
        {
            Tree *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if((*root)->right == NULL)
        {
            Tree *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else
        {
            Tree *temp = Tree_Max_Node((*root)->left);
            (*root)->data = temp->data;
            Tree_Delete(&(*root)->left, temp->data);
        }
    }
}
Tree* Tree_Max_Node(Tree *root)
{
    if(root == NULL)
        return NULL;
    else
    {
        while(root->right)
        {
            root = root->right;
        }
        return root;
    }
}
int Tree_Search(Tree *root, treeEntry data)
{
    if(root == NULL)
        return 0;
    else if(root->data == data)
        return 1;
    else if(root->data > data)
        return Tree_Search(root->left, data);
    else
        return Tree_Search(root->right, data);
}
void Tree_Traverse(Tree *root, void (*funPtr)(treeEntry),Traverse_Method Method)
{
    if(root)
    {
        if(Method == IN_ORDER)
        {
            Tree_Traverse(root->left,funPtr,Method);
            funPtr(root->data);
            Tree_Traverse(root->right,funPtr,Method);
        }
        else if (Method == PRE_ORDER)
        {
            funPtr(root->data);
            Tree_Traverse(root->left,funPtr,Method);
            Tree_Traverse(root->right,funPtr,Method);
        }
        else if (Method == POST_ORDER)
        {
            Tree_Traverse(root->left,funPtr,Method);
            Tree_Traverse(root->right,funPtr,Method);
            funPtr(root->data);
        }
    }
}

int Tree_Max(Tree *root)
{
    if(root == NULL)
        return -1;
    else
    {
        while(root->right)
        {
            root = root->right;
        }
        return root->data;
    }
}
int Tree_Min(Tree *root)
{
    if(root == NULL)
        return -1;
    else
    {
        while(root->left)
        {
            root = root->left;
        }
        return root->data;
    }
}
