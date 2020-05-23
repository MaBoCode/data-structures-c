//
// Created by matt on 5/18/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

st_stack *st_create(unsigned int capacity) {
    st_stack *stack = (st_stack*) malloc(sizeof(st_stack));

    stack->top = -1;
    stack->capacity = capacity;
    stack->items = malloc(capacity * sizeof(int));
    return stack;
}

int st_is_full(st_stack *stack) {
    return stack->top == stack->capacity - 1 ? 0 : -1;
}

int st_is_empty(st_stack *stack) {
    return stack->top == -1 ? 0 : -1;
}

void st_push(st_stack *stack, int value) {
    if(st_is_full(stack) == -1) {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

int st_pop(st_stack *stack) {
    if(st_is_empty(stack) == -1) {
        stack->top--;
        return stack->items[stack->top];
    }
    return -1;
}



void st_print(st_stack *stack) {
    for(unsigned int i = stack->capacity - 1; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}