#include "NodeAVL.h"

int32_t size_node = sizeof(NodeAVL);
int height(NodeAVL *N) { return N == NULL ? -1 : N->height;} 
  
void AVLTree_Init(NodeAVL** rootDest)
{
    (* rootDest) = malloc(size_node);
    (* rootDest)->height = -1; 
}

void AVLTree_SetNode(NodeAVL* source, NodeAVL*  rootDest)
{
    rootDest->data      = source->data;
    rootDest->height    = source->height;
    rootDest->key       = source->key;
    rootDest->left      = source->left;
    rootDest->right     = source->right;
}

void rightRotate( NodeAVL *y)
{
    NodeAVL* current = malloc(size_node);
    AVLTree_SetNode(y, current);
    NodeAVL* x = current->left;
    NodeAVL* T2 = x->right;

    x->right = current;
    current->left = T2;

    current->height = __max(height(current->left), height(current->right))+1;
    x->height = __max(height(x->left), height(x->right))+1;
    
    AVLTree_SetNode(x,y);
}

void leftRotate(NodeAVL* x)
{
    ///    10                20
    ///      \              /  \
    ///      20       =>   10   30
    ///         \
    ///          30
    
    NodeAVL* current = malloc(size_node);
    AVLTree_SetNode(x, current);
    NodeAVL* y = current->right; 
    NodeAVL* T2 = y->left;    

    y->left = current; 
    current->right = T2; 
    
    current->height = __max(height(current->left), height(current->right)) + 1;   
    y->height  = __max(height(y->left), height(y->right)) + 1;   
    
    AVLTree_SetNode(y, x);  
}

int AVLTree_Balance(NodeAVL* N, int key)
{
    int  balanceValue = height(N->left) - height(N->right);  
    int state = 1;
    
    if(balanceValue > 1)
    { 
        if( key < N->left->key)
        { 
            rightRotate(N); 
        }
        else if( key > N->left->key)
        {
            
            leftRotate(N->left); 
            rightRotate(N); 
        }
        else 
        {
            state = 0;
        }
    }
    else if(balanceValue < -1)
    { 
        
        if(key > N->right->key)
        {
            
            leftRotate(N);
        }
        else if( key < N->right->key)
        { 
            rightRotate(N->right); 
            leftRotate(N); 
        }
        else 
        {
            state = 0;
        } 
    }
 
    return state;
}
 
void AVLTree_Add( uint32_t key, void* data, NodeAVL*  rootDest)
{  
        //============ Add node binary tree ======
    
        NodeAVL* new_node   =  malloc(size_node);
        new_node->key   = key;
        new_node->left   = NULL;
        new_node->right  = NULL; 
        new_node->data = data; 
        new_node->height = 0;
        // add first node:
        if (rootDest->height == -1) 
        { 
            AVLTree_SetNode(new_node, rootDest);
            free(new_node);
            return;
        } 
        // add more node 
        NodeAVL* current = rootDest; 
        int8_t isUpHeight = 0;  
        // tranversal to null
        while (1)
        { 
            // move pointer if pointer->next exists 
            if(key < current->key && current->left != NULL)
            {
                current = current->left;  
            }
            else if(key > current->key && current->right != NULL)
            {
                 current = current->right;  
            }
            // finish move
            else if(key != current->key)
            {    
                isUpHeight = (current->height < 1); 
                // add new node
                if(key < current->key)
                {
                    current->left = malloc(size_node);
                    AVLTree_SetNode(new_node, current->left); 
                }
                else
                {
                    current->right = malloc(size_node);
                    AVLTree_SetNode(new_node, current->right);   
                }  
                free(new_node); 
                break;
            }
           
            
        } 
    
        if(isUpHeight)
        {
            NodeAVL* currentH = rootDest; 
            while (1)
            {
                if(key != currentH->key)
                    currentH->height+=1;// vào đường chuẩn mới cộng thêm chiều cao cho các node đi qua.
                if(key < currentH->key && currentH->left != NULL)
                    currentH = currentH->left;  
                else if(key > currentH->key && currentH->right != NULL)
                    currentH = currentH->right;  
                else
                break; 
            }
        }
        //=====================Balance Tree===================
        
        int32_t balanceFactor; 
        NodeAVL* currentB = rootDest;
        while (1)
        {
            balanceFactor = height(currentB->left) - height(currentB->right);
            printf("\nBlance factor = %d\n", balanceFactor);
            if(balanceFactor < -1) // lệch phải: trái < phải
            {
                if(key > currentB->right->key)
                    leftRotate(currentB);
                else if(key < currentB->right->key)
                {
                    rightRotate(currentB->right); 
                    leftRotate(currentB); 
                } 
            }
            if(balanceFactor > 1)
            { 
                if( key < currentB->left->key)
                { 
                    rightRotate(currentB); 
                }
                else if( key > currentB->left->key)
                {
                    
                    leftRotate(currentB->left); 
                    rightRotate(currentB); 
                } 
            }
            else
            {
                break;
            }
        }

}

NodeAVL* AVLTree_Search(NodeAVL* root, uint32_t key)
{
     NodeAVL* tmp  = root;
     while (tmp != NULL) {
       if ( key < tmp->key )
          tmp =  tmp->left;
       else if( key > tmp->key )
          tmp = tmp->right;
       else
         return tmp;
     }
     return tmp;
}

void AVLTree_DisplayKey(NodeAVL *root) 
{ 
    printf("\n================ AVLTree_DisplayKey ===============\n");
    if(root != NULL)
    {
        NodeAVL* ptr_left  = root->left;  
        NodeAVL* ptr_right = root->right;
        printf("ptr_root[%d](key: %d, height: %d)\n", &root, root->key, root->height); 
        while (1)
        {  
            if(ptr_left != NULL)
            { 
                printf("ptr_left[%d](key: %d, height: %d)\n", &ptr_left , ptr_left->key, ptr_left->height);
                
                if(ptr_left->right != NULL)
                {
                    NodeAVL* newNode = ptr_left->right;
                    newNode->right = ptr_right;
                    ptr_right = newNode ; 
                }  
                if(ptr_left->left != NULL)  
                { 
                  ptr_left = ptr_left->left;   
                } 
                else
                   ptr_left = NULL;  
            }   
            else
            {   
                if(ptr_right != NULL)
                {
                    printf("ptr_right[%d](key: %d, height: %d)\n", &ptr_right , ptr_right->key, ptr_right->height);
                    
                    if(ptr_right->left != NULL) 
                    {
                       ptr_left = ptr_right->left;
                       if(ptr_left->left == NULL)
                          ptr_right->left = NULL; 
                       continue;
                    }   
                    if(ptr_right->right != NULL)
                       ptr_right = ptr_right->right;
                    else
                    {
                        break;
                    }
                }
                else
                     break;
            }
        } 
    }
    else
    {
        printf("Tree empty!\n"  );
    } 
} 