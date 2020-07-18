//
// Created by matt on 5/17/20.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct {
	int data;
	struct dll_item* prev;
	struct dll_item* next;
} dll_item;

typedef struct {
	unsigned int size;
	dll_item* head;
} dll_list;

dll_item* dll_create_item(int data);
dll_list* dll_create_list();

void dll_add(dll_list* list, int data);
void dll_add_at(dll_list* list, unsigned int index, int data);

unsigned int dll_index_of(dll_list* list, int data);
unsigned int dll_last_index_of(dll_list* list, int data);

void dll_clear(dll_list* list);

int dll_contains(dll_list* list, int data);

int dll_get(dll_list* list, unsigned int index);

int dll_remove(dll_list* list, unsigned int index);

void dll_print_list(dll_list* list);

#endif //DOUBLY_LINKED_LIST_H
