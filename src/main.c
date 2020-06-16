#include <stdio.h>
#include "stack.h"

void test_stack() {
    st_stack *stack = st_create(10);

    if(st_is_empty(stack)) {
        printf("[Info] Stack is empty\n");
    }

    st_print(stack);
}

int main(void) {

    test_stack();

    return 0;
}