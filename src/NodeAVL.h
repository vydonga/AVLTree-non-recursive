#ifndef _NODE_AVL_H_
#define _NODE_AVL_H_
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
typedef struct NodeAVL NodeAVL;
typedef struct NodeAVL
{
    NodeAVL* left;
    NodeAVL* right;
    uint32_t key;
    int height;
    void* data;
} NodeAVL;
extern void AVLTree_Init(NodeAVL** rootDest);
extern void AVLTree_Add( uint32_t key,void* data,NodeAVL*  rootDest );
extern NodeAVL* AVLTree_Search(  NodeAVL* root, uint32_t key);
extern void AVLTree_DisplayKey(NodeAVL *root)  ;
#endif