#include "singly_linked_list.h"

int main(void) {

    sll_list *list = sll_create_list();

    sll_add(list, "Test");
    sll_print_list(list);
}