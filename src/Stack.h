#ifndef _STACK_H_123
#define _STACK_H_123
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h> 
typedef struct Stack { 
    void** array; 
    int32_t top; 
    uint32_t capacity;  
}Stack; 
  
extern Stack* Stack_Init(uint32_t capacity); 
extern int Stack_isFull( Stack* stack); 
extern int Stack_isEmpty( Stack* stack);  
extern void Stack_Push(  Stack* stack, void* item);
extern void* Stack_Pop( Stack* stack);
extern void* Stack_Peek(  Stack* stack);
  

#endif