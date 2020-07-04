//
// Created by matt on 5/18/20.
//

#include <stdio.h>
#include "stack.h"

void test_stack() {
	st_stack *stack = st_create(3);

	st_push(stack, 3);
	st_push(stack, 2);
	st_push(stack, 1);

	st_print(stack);

	printf("4 is at %d from top of stack\n", st_search(stack, 4));

	printf("Popping %d from stack\n", st_pop(stack));

	st_print(stack);

	printf("Peek from stack %d\n", st_peek(stack));
}
