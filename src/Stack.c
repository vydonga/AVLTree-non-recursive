#include "Stack.h"
void AutoOpacity(Stack** stack)
{
     (*stack)->capacity *= 2;
     (*stack)->array = (void**)realloc( (*stack)->array, (*stack)->capacity * sizeof(void*)); 
}
Stack* Stack_Init(uint32_t capacity) 
{ 
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (void**)malloc(stack->capacity * sizeof(void*)); 
    return stack; 
} 
int Stack_isFull( Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
int Stack_isEmpty( Stack* stack) 
{ 
    return stack->top == -1; 
} 
void Stack_Push(Stack* stack, void* item) 
{ 
    if (Stack_isFull(stack)) 
    {
        AutoOpacity(&stack);
    }
    stack->array[++stack->top] = item;  
} 
void* Stack_Pop(Stack* stack) 
{ 
    if (Stack_isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top--]; 
} 
void* Stack_Peek(  Stack* stack) 
{ 
    if (Stack_isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top]; 
} 