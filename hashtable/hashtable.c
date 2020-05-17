//
// Created by Matthias Brown Marie on 28/04/2020.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hashtable.h"

ht_item *ht_create_item(const char *key, const char* data) {
    ht_item *item = (ht_item*) malloc(sizeof(ht_item));

    if(item == NULL) {
        fprintf(stderr, "Couldn't allocate memory for item\n");
        exit(1);
    }
    item->key = strdup(key);
    item->data = strdup(data);
    item->next = NULL;

    return item;
}

ht_table *ht_create_table(int capacity) {
    ht_table *table = (ht_table*) malloc(sizeof(ht_table));

    if(table == NULL) {
        fprintf(stderr, "Couldn't allocate memory for table\n");
        exit(1);
    }
    table->capacity = capacity;
    table->size = 0;
    table->items = calloc(table->capacity, sizeof(ht_item*));
}

/**
 * Polynomial rolling hash function
 * Formula: sum( (s[i] * p^i) ) % m from i = 0 to n -1
 * where s is the key, p is a prime number greater than the input alphabet
 * m is the capacity of the table, n is the length of the key
 * The choosen alphabet is all lowercase letters and digits
 * @param table
 * @param key
 * @return the hash
 */
unsigned int ht_get_hash(int capacity, const char *key) {
    int p = 37;
    int m = capacity;
    unsigned long int hash = 0;

    for(int i = 0; i < strlen(key); i++) {
        hash += key[i] * (int) pow(p, i);
    }
    return hash % m;
}

void ht_put(ht_table *table, const char *key, const char *data) {
    unsigned int index = ht_get_hash(table->capacity, key);

    ht_item *item = table->items[index];

    if(item == NULL) {
        table->items[index] = ht_create_item(key, data);
        return;
    }

    
}

ht_item *ht_get(ht_table *table, char *key) {
    int index = ht_get_hash(table->capacity, key);
    ht_item* item = table->items[index];

    while (item != NULL) {
        if(strcmp(item->key, key) == 0)
            return item;
        ++index;
        index %= table->capacity;
        item = table->items[index];
    }
    return NULL;
}

void ht_delete(ht_table *table, char *key) {
    ht_item *item = ht_get(table, key);

    if(item != NULL) {
        ht_delete_item(table, item);
    }
}

void ht_delete_item(ht_table* table, ht_item *item) {
    free(item->key);
    free(item->data);
    free(item);
    table->size--;
}

void ht_delete_table(ht_table *table) {
    for(int i = 0; i < table->size; i++) {
        ht_item *item = table->items[i];
        if(item != NULL)
            ht_delete_item(table, item);
    }

    free(table->items);
    free(table);
}

void ht_print_item(ht_table *table, char *key) {
    ht_item *item = ht_get(table, key);
    printf("key = %s, data = %s\n", item->key, item->data);
}

void ht_print_table(ht_table *table) {
    for (int i = 0; i < table->capacity; i++) {
        printf("%s\n", table->items[i]->data);
    }
}
