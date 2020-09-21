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
  
extern Stack* createStack(uint32_t capacity); 
extern int isFull( Stack* stack); 
extern int isEmpty( Stack* stack);  
extern void push(  Stack* stack, void* item);
extern void* pop( Stack* stack);
extern void* peek(  Stack* stack);
  

#endif