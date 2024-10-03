#include "shared.h"

typedef struct Stack{
    // The index of the top element
    int _top;
    // The capacity of the stack
    int capacity;
    // The array to store data of the stack
    point* _stack;
} stack;

// Initialize the value of the stack
stack init_stack(); 
// Return the top element of the stack
point s_top(stack s);
// Return the size of the stack
int s_size(stack s);
// Check if the stack is empty
int s_empty(stack s);
// Insert a new element on top of the stack
void s_push(stack *s, point p);
// Pop out the top element in the stack
void s_pop(stack *s);
