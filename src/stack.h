//
// Created by matt on 5/18/20.
//

#ifndef DATA_STRUCTURES_C_STACK_H
#define DATA_STRUCTURES_C_STACK_H

typedef struct {
    unsigned int top;
    unsigned int capacity;
    void **items;
} st_stack;

st_stack *st_create(unsigned int capacity);

void st_push(st_stack *stack, void *value);
void *st_pop(st_stack *stack);
void *st_peek(st_stack *stack);
int st_search(st_stack *stack, void *value);

int st_is_full(st_stack *stack);
int st_is_empty(st_stack *stack);

void st_free(st_stack *stack);

void st_print(st_stack *stack);

#endif //DATA_STRUCTURES_C_STACK_H
