//
// Created by matt on 5/17/20.
//

##include "doubly_linked_list.h"

int main(void) {
	dll_list* list = dll_create_list();

	dll_add(list, 5);
	dll_add(list, 10);
	dll_add(list, -5);
	dll_add(list, 9);
	dll_add(list, 5);
	dll_add(list, -10);
	dll_print_list(list);

	if (dll_contains(list, -10) == 0) {
		printf("List contains %d\n", -10);
	}

	printf("4th element is %d\n", dll_get(list, 3));

	printf("Index of -5 is %d\n", dll_index_of(list, -5));

	printf("Last index of 5 is %d\n", dll_last_index_of(list, 5));

	printf("Adding 3 at 3...\n");
	dll_add_at(list, 3, 3);
	dll_print_list(list);

	int r1 = dll_remove(list, 0);
	printf("Removing %d..\n", r1);
	dll_print_list(list);

	dll_remove(list, 5);

	int r2 = dll_remove(list, 3);
	printf("Removing %d..\n", r2);
	dll_print_list(list);

	int r3 = dll_remove(list, list->size-1);
	printf("Removing %d..\n", r3);
	dll_print_list(list);

	dll_clear(list);
	dll_print_list(list);
}
