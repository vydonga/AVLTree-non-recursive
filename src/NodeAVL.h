#ifndef _NODE_AVL_H_
#define _NODE_AVL_H_
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <Stack.h> 
typedef struct Stack Stack;
typedef struct NodeAVL NodeAVL;
typedef struct NodeAVL
{
    NodeAVL* left;
    NodeAVL* right; 
    void* data;
    int16_t key;
    uint16_t height; 
    int16_t balance; 
} NodeAVL;
extern void AVLTree_Init(NodeAVL** rootDest);
extern void AVLTree_Insert(int16_t key,void* data,NodeAVL*  rootDest );
extern NodeAVL* AVLTree_Search(  NodeAVL* root, int16_t key);
extern void AVLTree_DisplayKey(NodeAVL *root)  ;
extern void AVLTree_DisplayRecursive(NodeAVL *root);
#endif