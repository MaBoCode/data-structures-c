//
// Created by matt on 5/17/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

dll_list* dll_create_list() {
	dll_list* list = (dll_list*) malloc(sizeof(dll_list));

	if (list == NULL) {
		fprintf(stderr, "Can't allocate memory for list\n");
		exit(EXIT_FAILURE);
	}

	list->size = 0;
	list->head = NULL;
	return list;
}

dll_item* dll_create_item(int data) {
	dll_item* item = (dll_item*) malloc(sizeof(dll_item));

	if (item == NULL) {
		fprintf(stderr, "Can't allocate memory for item\n");
		exit(EXIT_FAILURE);
	}

	item->data = data;
	item->prev = NULL;
	item->next = NULL;
	return item;
}

void dll_add(dll_list* list, int data) {
	if (list == NULL) {
		return;
	}

	dll_item* item = dll_create_item(data);

	if (list->head == NULL) {
		list->head = item;
		list->size++;
		return;
	}

	dll_item* tmp = list->head;
	dll_item* prev;

	while (tmp->next != NULL) {
		prev = tmp;
		tmp = tmp->next;
	}
	item->prev = prev;
	tmp->next = item;
	list->size++;
}

void dll_add_at(dll_list* list, unsigned int index, int data) {
	if (list == NULL) {
		return;
	}

	if (index < 0 || index >= list->size) {
		fprintf(stderr, "Index out of bounds\n");
		return;
	}

	dll_item* item = dll_create_item(data);

	dll_item* tmp = list->head;
	dll_item* prev;
	unsigned int counter = 0;

	while (counter != index) {
		prev = tmp;
		tmp = tmp->next;
		counter++;
	}

	prev->next = item;
	item->next = tmp;
	list->size++;
}

unsigned int dll_index_of(dll_list* list, int data) {
	if (list == NULL) {
		return;
	}

	dll_item* tmp = list->head;
	unsigned int index = 0;

	while (tmp->data != data) {
		tmp = tmp->next;
		index++;
	}
	return index;
}

unsigned int dll_last_index_of(dll_list* list, int data) {
	if (list == NULL) {
		return;
	}

	dll_item* tmp = list->head;
	unsigned int index = -1;
	unsigned int counter = 0;

	while (tmp != NULL) {
		if (tmp->data == data) {
			index = counter;
		}
		tmp = tmp->next;
		counter++;
	}
	return index;
}

int dll_contains(dll_list* list, int data) {
	if (list == NULL) {
		return;
	}

	dll_item* tmp = list->head;

	while (tmp != NULL) {
		if (tmp->data == data) {
			return 0;
		}
		tmp = tmp->next;
	}
	return -1;
}

int dll_get(dll_list* list, unsigned int index) {
	if (list == NULL) {
		return;
	}

	if (index < 0 || index >= list->size) {
		fprintf(stderr, "Index out of bounds\n");
		return;
	}

	dll_item* tmp = list->head;
	int counter = 0;

	while (counter != index) {
		tmp = tmp->next;
		counter++;
	}

	if (tmp != NULL) {
		return tmp->data;
	}
}

int dll_remove(dll_list* list, unsigned int index) {
	if (list == NULL) {
		return;
	}

	if (index < 0 || index >= list->size) {
		fprintf(stderr, "Index out of bounds\n");
		return;
	}

	dll_item* tmp = list->head;

	if (index == 0) {
		dll_item* next = tmp->next;
		next->prev = NULL;
		list->head = next;
		list->size--;
		return tmp->data;
	}

	dll_item* prev;
	int counter = 0;

	while (counter != index) {
		prev = tmp;
		tmp = tmp->next;
		counter++;
	}

	int data = tmp->data;

	if (index == (list->size - 1)) {
		prev->next = NULL;
		free(tmp);
		list->size--;
		return data;
	}

	dll_item* next = tmp->next;
	next->prev = prev;
	prev->next = tmp->next;
	free(tmp);
	list->size--;
	return data;
}

void dll_clear(dll_list* list) {
	if (list == NULL) {
		return;
	}

	dll_item* tmp = list->head;
	dll_item* next;

	while (tmp != NULL) {
		next = tmp->next;
		tmp->next = NULL;
		free(tmp);
		tmp = next;
		list->size--;
	}
	list->head = NULL;
}

void dll_print_list(dll_list* list) {
	if (list == NULL) {
		return;
	}

	dll_item* tmp = list->head;
	printf("[ ");
	while (tmp != NULL) {
		printf("%d, ", tmp->data);
		tmp = tmp->next;
	}
	printf("]\n");
}
