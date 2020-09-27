//
// Created by matt on 5/17/20.
//

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct {
    char *data;
    struct sl_item *next;
} sl_item;

typedef struct {
    unsigned int size;
    sl_item *head;
} sl_list;

sl_item *sl_create_item(const char *data);
sl_list *sl_create_list();

void sl_add(sl_list *list, const char *data);
void sl_add_at(sl_list *list, unsigned int index, const char *data);

void sl_remove(sl_list *list, const char *data);
void sl_remove_at(sl_list *list, unsigned int index);
void sl_remove_all(sl_list *list);

char *sl_get(sl_list *list, unsigned int index);
void sl_set(sl_list *list, unsigned int index, const char *data);

int sl_index_of(sl_list *list, const char *data);
int sl_last_index_of(sl_list *list, const char *data);

int sl_contains(sl_list *list, const char *data);
int sl_is_empty(sl_list *list);

void sl_destroy(sl_list *list);

void sl_print_list(sl_list *list);

#endif //SINGLY_LINKED_LIST_H
