#include "Stack.h"
void AutoOpacity(Stack** stack)
{
     (*stack)->capacity *= 2;
     (*stack)->array = (void**)realloc( (*stack)->array, (*stack)->capacity * sizeof(void*)); 
}
Stack* createStack(uint32_t capacity) 
{ 
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (void**)malloc(stack->capacity * sizeof(void*)); 
    return stack; 
} 
int isFull( Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
int isEmpty( Stack* stack) 
{ 
    return stack->top == -1; 
} 
void push(Stack* stack, void* item) 
{ 
    if (isFull(stack)) 
    {
        AutoOpacity(&stack);
    }
    stack->array[++stack->top] = item;  
} 
void* pop(Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top--]; 
} 
void* peek(  Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top]; 
} 