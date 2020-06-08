//
// Created by Matthias Brown Marie on 28/04/2020.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
    char *key;
    char *data;
    struct ht_item *next;
} ht_item;

typedef struct {
    int capacity;
    int size;
    ht_item **items;
} ht_table;

ht_item *ht_create_item(const char *key, const char *data);
ht_table *ht_create_table(int capacity);

unsigned int ht_get_hash(int capacity, const char *key);

void ht_put(ht_table* table, const char *key, const char* data);
char *ht_get(ht_table* table, const char *key);

void ht_delete(ht_table *table, const char *key);
void ht_delete_item(ht_table *table, ht_item *item);
void ht_delete_table(ht_table *table);

void ht_print_item(ht_table *table, const char *key);
void ht_print_table(ht_table *table);
#endif //HASHTABLE_H
