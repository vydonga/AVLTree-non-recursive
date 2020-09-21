#include "NodeAVL.h"
void rightRotate( NodeAVL *ro);
void leftRotate(NodeAVL* ro);

int32_t size_node = sizeof(NodeAVL);
int16_t isLeaf(NodeAVL* N){ return (N->left == NULL && N->right == NULL) ? 1 : 0; }
int16_t isHalfLeafLeft(NodeAVL* N){return (N->left != NULL && N->right == NULL)  ? 1 : 0;}
int16_t isHalfLeafRight(NodeAVL* N){return   (N->left == NULL && N->right != NULL) ? 1 : 0;}
uint16_t height(NodeAVL *N) {
    
    if(isLeaf(N)) return N->height = 1;
    else if(isHalfLeafLeft(N)) return N->height = N->left->height + 1;
    else if(isHalfLeafRight(N))  return N->height = N->right->height + 1;
    else return __max(N->left->height, N->right->height) + 1; 
}  
int16_t balance(NodeAVL *N) { 
    if(isLeaf(N)) return 0;
    else if(isHalfLeafLeft(N)) return N->height > 2 ? N->height : 1; 
    else if(isHalfLeafRight(N)) return N->height > 2 ? -N->height : -1; 
    else return N->left->height - N->right->height; // { -1, 0, 1 }
} 
void AVLTree_SetHB(NodeAVL** rootDest)
{
    (*rootDest)->height = height(*rootDest); 
    (*rootDest)->balance = balance(*rootDest);
}
void AVLTree_SetHBNode(NodeAVL** cBalance)
{
    if((*cBalance)->right != NULL)AVLTree_SetHB(&(*cBalance)->right);
    if((*cBalance)->left)AVLTree_SetHB(&(*cBalance)->left);
    AVLTree_SetHB(&(*cBalance));
}
void Node_Display(NodeAVL* N){
    printf("[%d](key: %d , height: %d , balance: %d) \n", &N, N->key, N->height, N->balance);
}
void AVLTree_Init(NodeAVL** rootDest)
{
    (* rootDest) = malloc(size_node);
    (* rootDest)->left = NULL;
    (* rootDest)->right = NULL; 
    (* rootDest)->height = 0; 
    (* rootDest)->balance = 0;
}
NodeAVL* AVLTree_SetData(int16_t key, void* data)
{
    NodeAVL* new_node;
    AVLTree_Init(&new_node);
    new_node->key   = key; 
    new_node->data  = data; 
    return new_node;
}

void AVLTree_SetNode(NodeAVL* source, NodeAVL**  rootDest)
{ 
    if(source != NULL)
    {
        if( (* rootDest) == NULL)
        {
            (* rootDest) = malloc(size_node); 
        }
        (* rootDest)->data      = source->data;
        (* rootDest)->height    = source->height;
        (* rootDest)->balance   = source->balance;
        (* rootDest)->key       = source->key;
        (* rootDest)->left      = source->left;
        (* rootDest)->right     = source->right;
    } 
}
 
void AVLTree_MovePtr( int16_t key, NodeAVL** current, uint8_t* isToLeaf)
{
    if(key < (*current)->key && (*current)->left != NULL)  (*current) = (*current)->left;  
    else if(key > (*current)->key && (*current)->right != NULL) (*current) = (*current)->right;  
    else  *isToLeaf = 1;
}
void AVLTree_InsertNode(int16_t key, NodeAVL* new_node, NodeAVL** current)
{
    // add new node
    if(key < (*current)->key)
    {
        (*current)->left = NULL;
        AVLTree_SetNode(new_node, &(*current)->left); 
    }
    else
    {
        (*current)->right = NULL;
        AVLTree_SetNode(new_node, &(*current)->right);   
    }  
}
  
void AVLTree_Balance(  NodeAVL** rootDest)
{
    int16_t balanceCur = 0;
    if(isHalfLeafLeft((* rootDest)) )
        balanceCur = height((* rootDest)->left);
    else if(isHalfLeafRight((* rootDest)) )  
        balanceCur =  - height((* rootDest)->right);  
    else if((* rootDest)->left != NULL && (* rootDest)->right != NULL)
    {
        balanceCur = height((* rootDest)->left) - height((* rootDest)->right);  
    } 
    
    
    if(abs(balanceCur) > 1)
    {
        
        int16_t height_right = (* rootDest)->right == NULL ? 0 : (* rootDest)->right->height; 
        int16_t height_left  = (* rootDest)->left == NULL ? 0 : (* rootDest)->left->height;
      
        if(balanceCur < -1)
        { 
            if(height_left - height_right < -1)
            {  
                leftRotate((* rootDest));   
            }
            else if(height_left - height_right > 1)
            { 
               leftRotate((* rootDest)); 
                rightRotate((* rootDest)); 
            }  
        }
        else if(balanceCur > 1)
        { 
            if(height_left - height_right > 1)
            { 
               
                 rightRotate((* rootDest));  
            }
            else if(height_left - height_right < -1)
            { 
              rightRotate((* rootDest)); 
                leftRotate((* rootDest));
               
            }
        }

        
    }
}
  
void AVLTree_Insert(int16_t key, void* data, NodeAVL*  rootDest)
{  
        //============ Add node binary tree ======
    
        NodeAVL* new_node = AVLTree_SetData(key, data);
        AVLTree_SetHB(&new_node);
        // chèn nốt đầu tiên vào cây
        if(rootDest->height == 0)
        {  
            AVLTree_SetNode(new_node, &rootDest); 
            free(new_node);
            return;
        } 
       
        NodeAVL* current = rootDest;  
        uint8_t isToleaf = 0 ;
        Stack* stack = createStack(100); 
        // chèn nốt mới vào cây
        while (1)
        {   
           
            push(stack, current);        
            AVLTree_MovePtr(key, &current, &isToleaf);
            if(isToleaf)
            {  
                AVLTree_InsertNode(key, new_node, &current);  
                free(new_node); 
                break;
            } 
        }  
        while (!isEmpty(stack))
        {
           
            NodeAVL* item = (NodeAVL*)pop(stack);
            AVLTree_SetHBNode(&item);  
            
            AVLTree_Balance(&item);
            AVLTree_SetHBNode(&item); 
        }
        
   
}

void leftRotate(NodeAVL* ro)
{ 
    //        ro                 rn 
    //      /   \        =>     /   \
    //          rn             ro    R 
    //         /   \              \     
    //        L     R              L 
    //

    // buffer
    NodeAVL* rn = ro->right;    
    ro->right = NULL;
    NodeAVL* rn_left = rn->left;  
    // if(rn_left != NULL) printf("\nrn_left: %d",rn_left->key); 
    rn->left = NULL;
    //rotation  
    AVLTree_SetNode(ro, &rn->left); 
    AVLTree_SetNode(rn_left, &rn->left->left->right);  

    AVLTree_SetNode(rn, &ro); 
}

void rightRotate( NodeAVL *ro) 
{ 
    //        ro               rn 
    //       /        =>     /   \
    //      rn              L     ro
    //    /   \                   /
    //   L       R             rn_right
    //

    // buffer
    NodeAVL *rn = ro->left; 
    ro->left = NULL;// cắt đứt phần nối cũ, trước khi nối mới
    NodeAVL *rn_right = rn->right;  
    rn->right = NULL;

    // rotation
    AVLTree_SetNode(ro, &rn->right);
    AVLTree_SetNode( rn_right, &rn->right->right->left);  
    
    // set result for new root
     AVLTree_SetNode(rn, &ro);
} 

NodeAVL* AVLTree_Search(NodeAVL* root, int16_t key)
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
    printf("\n============== AVLTree_DisplayKey: ==============\n");
    if(root != NULL)
    {
        printf("ptr_root ");Node_Display(root); 
        NodeAVL* ptr_left  = root->left;
        NodeAVL* ptr_right = root->right; 
       
        while (1)
        {  
            if(ptr_left != NULL)
            { 
                printf("ptr_left ");Node_Display(ptr_left);  
                if(ptr_left->right != NULL)
                {
                    NodeAVL* tmp = ptr_left->right;
                    while (1)
                    {
                        printf("ptr_right ");Node_Display(tmp);  
                        tmp = tmp->right;
                        if( tmp == NULL) break;
                    }
                }
                ptr_left = ptr_left->left;;
                 
               
            }    
            else if(ptr_right != NULL)
            {
                if(ptr_right->left != NULL)
				{
					NodeAVL* tmp = ptr_right->left;
					while (1)
					{
					    printf("ptr_left ");Node_Display(tmp);  
						tmp = tmp->left;
						if( tmp == NULL) break;
					}
				}
                printf("ptr_right ");Node_Display(ptr_right);
				ptr_right = ptr_right->right;
            } 
            else
		    	break;
        }  
    }
    else
    {
        printf("Tree empty!\n"  );
    } 
} 

void AVLTree_DisplayRecursive(NodeAVL *root)
{
    if(root)
    {
        Node_Display(root);
        AVLTree_DisplayRecursive(root->left);
        AVLTree_DisplayRecursive(root->right);
    }
}