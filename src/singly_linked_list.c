//
// Created by matt on 5/17/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"

sl_item *sl_create_item(const char *data) {
	sl_item *item = (sl_item *) malloc(sizeof(sl_item));

	if(item == NULL) {
		fprintf(stderr, "Couldn't allocate memory for item\n");
		exit(1);
	}
	item->data = strdup(data);
	item->next = NULL;
	return item;
}

sl_list *sl_create_list() {
	sl_list *list = (sl_list *) malloc(sizeof(sl_list));

	if(list == NULL) {
		fprintf(stderr, "Couldn't allocate memory for list\n");
		exit(1);
	}
	list->size = 0;
	list->head = NULL;
	return list;
}

void sl_add(sl_list *list, const char *data) {
	if(list->head == NULL) {
		list->head = sl_create_item(data);
		list->size++;
		return;
	}

	sl_item *tmp = list->head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = sl_create_item(data);
	list->size++;
}

void sl_add_at(sl_list *list, unsigned int index, const char *data) {

	if(list->head == NULL) return;

	if(index >= list->size) {
		fprintf(stderr, "Index out of range\n");
		exit(1);
	}

	sl_item *tmp = list->head;
	sl_item *item = sl_create_item(data);

	if(index == 0) {
		item->next = list->head;
		list->head = item;
		list->size++;
		return;
	}

	sl_item *prev;
	unsigned int counter = 0;

	while (tmp->next != NULL) {
		if(counter == index) {
			item->next = tmp;
			prev->next = item;
			list->size++;
			return;
		}
		counter++;
		prev = tmp;
		tmp = tmp->next;
	}
}

void sl_remove(sl_list *list, const char *data) {
	if(list->head == NULL) {
		return;
	}

	sl_item *tmp = list->head;
	sl_item *prev;

	while (tmp->next != NULL) {
		if(strcmp(tmp->data, data) == 0) {
			prev->next = tmp->next;
			free(tmp);
			list->size--;
			return;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void sl_remove_at(sl_list *list, unsigned int index) {

	if(list->head == NULL) {
		return;
	}

	if(index >= list->size) {
		fprintf(stderr, "Index out of range\n");
		exit(1);
	}

	sl_item *tmp = list->head;

	if(index == 0) {
		list->head = tmp->next;
		free(tmp);
		list->size--;
		return;
	}

	sl_item *prev;
	int counter = 0;

	while (tmp->next != NULL) {
		if(counter == index) {
			prev->next = tmp->next;
			free(tmp);
			list->size--;
			return;
		}
		counter++;
		prev = tmp;
		tmp = tmp->next;
	}
}

void sl_remove_all(sl_list *list) {
	sl_item *tmp = list->head;
	sl_item *next;

	while (tmp != NULL) {
		next = tmp->next;
		free(tmp);
		tmp = next;
		list->size--;
	}
	list->head = NULL;
}


char *sl_get(sl_list *list, unsigned int index) {
	if(list->head == NULL) {
		return;
	}

	if(index == 0) {
		return list->head->data;
	}

	sl_item *tmp = list->head;
	unsigned int counter = 0;
	while (tmp != NULL) {
		if(counter == index) {
			return tmp->data;
		}
		counter++;
		tmp = tmp->next;
	}
}

void sl_set(sl_list *list, unsigned int index, const char *data) {
	if(list->head == NULL) return;

	if(index == 0) {
		free(list->head->data);
		list->head->data = strdup(data);
		return;
	}

	sl_item *tmp = list->head;
	unsigned int counter = 0;
	while (tmp != NULL) {
		if(counter == index) {
			free(tmp->data);
			tmp->data = strdup(data);
			return;
		}
		counter++;
		tmp = tmp->next;
	}
}

int sl_index_of(sl_list *list, const char *data) {
	if(list->head == NULL) return;

	sl_item *tmp = list->head;
	unsigned int index = 0;

	while (tmp != NULL) {
		if(strcmp(tmp->data, data) == 0) {
			return index;
		}
		index++;
		tmp = tmp->next;
	}
	return -1;
}

int sl_last_index_of(sl_list *list, const char *data) {
	if(list->head == NULL) return -1;

	sl_item *tmp = list->head;
	int counter = 0;
	int index = -1;

	while (tmp != NULL) {
		if(strcmp(tmp->data, data) == 0) {
			index = counter;
		}
		counter++;
		tmp = tmp->next;
	}
	return index;
}

int sl_contains(sl_list *list, const char *data) {
	if(list->head == NULL) {
		return -1;
	}

	sl_item *tmp = list->head;
	while (tmp != NULL) {
		if(strcmp(tmp->data, data) == 0) {
			return 0;
		}
		tmp = tmp->next;
	}
	return -1;
}

int sl_is_empty(sl_list *list) {
	if(list->head == NULL) return 0;

	return -1;
}

void sl_destroy(sl_list *list) {
	sl_remove_all(list);
	free(list);
}

void sl_print_list(sl_list *list) {
	sl_item *tmp = list->head;
	unsigned int index = 0;
	while (tmp != NULL) {
		printf("%d: \"%s\", ", index, tmp->data);
		index++;
		tmp = tmp->next;
	}
	printf("\n");
}
