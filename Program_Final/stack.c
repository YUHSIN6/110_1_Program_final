#include "stack.h"

stack init_stack(){
    stack new_stack;
    new_stack._top = 0;
    new_stack.capacity = 10;
    new_stack._stack = (point*)malloc(new_stack.capacity*sizeof(point));
    return new_stack;
}

point s_top(stack s){
    if(s_empty(s)){
        printf("> Error : Try to retrieve elements from empty stack in s_top.\n> Location : In stack.c, point s_top().\n");
        return make_point(0, 0);
    }
    return s._stack[s._top-1];
}

int s_size(stack s){
    return s._top;
}

int s_empty(stack s){
    return !s._top;
}

void s_push(stack *s, point p) {
    if(s->_top == s->capacity) {
        s->capacity *= 2;
        point *temp;
        temp = (point *)realloc(s->_stack, s->capacity*sizeof(point));
        if (temp) // Remember to avoid the case that failed to realloc
            s->_stack = temp;
        else{
            printf ("> Error : Failed to realloc in s_push.\n> Location : In stack.c, void s_push().\n");
            return;
        }
    }
    s->_stack[s->_top++] = p;
}

void s_pop(stack *s) {
    s->_top -= !s_empty(*s);
}