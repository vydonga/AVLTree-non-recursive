#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <NodeAVL.h>

///
/// Recursive là phương pháp truy cập tree đến cuối, sau đó mới tiến hành làm việc ngược trở lại những nốt cha
/// => giải pháp:
        /// - dùng stack để LIFO: vào sau ra trước. để truy cập từ phần tử con đến phần tử cha.
///
typedef struct SV
{
    int id;
    char* name;
} SV;
typedef struct NodeAVL NodeAVL;
 
int 
main()
{ 
    int size = sizeof(SV);

    SV* sv1 = malloc(size);
    sv1->id = 1230;
    sv1->name = "Vy dong A";

    SV* sv2 = malloc(size);
    sv2->id = 2;
    sv2->name = "Vy dong B";

    SV* sv3 = malloc(size);
    sv3->id = 3;
    sv3->name = "Vy dong C";

    SV* sv4 = malloc(size);
    sv4->id = 4;
    sv4->name = "Vy dong D";

    SV* sv5 = malloc(size);
    sv5->id = 5;
    sv5->name = "Vy dong E";

    SV* sv6 = malloc(size);
    sv6->id = 6;
    sv6->name = "Vy dong F";

    
    NodeAVL* root;
    AVLTree_Init(&root);

    AVLTree_Insert( 1, sv1, root);   
    AVLTree_Insert( 2, sv2, root);  
    AVLTree_Insert( 3, sv3, root); 
    AVLTree_Insert( 4, sv4, root);  
    AVLTree_Insert( 5, sv5, root);
    AVLTree_Insert( 6, sv6, root);    
    AVLTree_Insert( 7, sv2, root); 
    AVLTree_Insert( 8, sv1, root);

    // 2 1 3 4
	// root = insert(root, 5); 
    // 2 1 4 3 5
	// root = insert(root, 6);
    // 4 2 1 3 5 6
    
    printf("\n======Recursive========\n"); AVLTree_DisplayRecursive(root);
    printf("\n==============\n"); AVLTree_DisplayRecursive(root);
    printf("\n==============\n");  AVLTree_DisplayRecursive(root);
    printf("\n==============\n");   AVLTree_DisplayRecursive(root);
    AVLTree_DisplayKey(root);
    AVLTree_DisplayKey(root);
    AVLTree_DisplayKey(root);
    AVLTree_DisplayKey(root);
    AVLTree_DisplayKey(root);
    
    // exemple get data
    NodeAVL* result = AVLTree_Search(root, 4); 
    SV* svresult = (SV*)result->data;
    printf("ID: %d, name: %s\n", svresult->id, svresult->name); 
  
    free(root);
    free(sv1);
    free(sv2);
    free(sv3);
    free(sv4);
    free(sv5);
    free(sv6);
    root = NULL;
    sv1 = sv2 = sv3 = sv4 = sv5 = NULL; 
  
    fflush(stdin);
    getchar();
    return 0;
}
