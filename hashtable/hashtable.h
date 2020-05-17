//
// Created by Matthias Brown Marie on 28/04/2020.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
    char* key;
    char* data;
} ht_item;

typedef struct {
    int capacity;
    int size;
    ht_item **items;
} ht_table;

ht_item *ht_create_item(char *key, char *data);
ht_table *ht_create_table(int capacity);

int ht_get_hash(int capacity, char *key);

void ht_put(ht_table* table, char *key, char* data);
ht_item *ht_get(ht_table* table, char *key);

void ht_delete(ht_table *table, char *key);
void ht_delete_item(ht_table *table, ht_item *item);
void ht_delete_table(ht_table *table);

void ht_print_item(ht_table *table, char *key);
void ht_print_table(ht_table *table);
#endif //HASHTABLE_H
