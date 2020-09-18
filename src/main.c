#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <macro.h>
#include <NodeAVL.h>
typedef struct SV SV;
typedef struct NodeAVL NodeAVL;
int 
main()
{
    // Hello();//53.6 KB (54,957 bytes) - 56.0 KB (57,344 bytes)
    SV sv = {
        "vy dong a",
        123
    }; 
    int a = print(42);
    double b = print(3.14);
    SV sv_output = print(sv);
    printf("a: %d\n",a);
    printf("b: %lf\n",b);
    printf("sv.name: %s, sv.id: %d\n", sv_output.name, sv_output.id);
    print("hello, world");
    printf("=============================\n");

    NodeAVL* root;
    AVLTree_Init(&root);

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

    
    
    AVLTree_Add( 10, sv1, root);  
    AVLTree_Add( 20, sv2, root);  
    AVLTree_Add( 30, sv3, root);
    AVLTree_Add( 40, sv4, root); 
    AVLTree_Add( 50, sv5, root); 
    AVLTree_Add( 25, sv6, root); 
    
    AVLTree_DisplayKey(root);
    
    // NodeAVL* result = AVLTree_Search(root, 25); 
    // SV* svresult = (SV*)AVLTree_Search(root, 20)->data;
    // printf("ID: %d, name: %s\n", svresult->id, svresult->name);
    // free(result);
    // free(root);

    // result = root = NULL;
    // if(result != NULL)
    // printf("ID: %d, name: %s\n", ((SV*)result->data)->id, ((SV*)result->data)->name);
    fflush(stdin);
    getchar();
    return 0;
}