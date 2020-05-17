//
// Created by Matthias Brown Marie on 28/04/2020.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hashtable.h"

ht_item *ht_create_item(char *key, char* data) {
    ht_item *item = (ht_item*) malloc(sizeof(ht_item));

    if(item == NULL) {
        fprintf(stderr, "Couldn't allocate memory for item\n");
        exit(1);
    }
    /*
    size_t key_length = sizeof(key);
    item->key = (char*) malloc(key_length);
    memcpy(item->key, key, key_length);
     */
    item->key = strdup(key);
    item->data = strdup(data);
    return item;
}

ht_table *ht_create_table(int capacity) {
    ht_table *table = (ht_table*) malloc(sizeof(ht_table));
    table->capacity = capacity;
    table->size = 0;
    table->items = calloc(table->capacity, sizeof(ht_item*));
}

/**
 * Polynomial rolling hash function
 * Formula: sum( (s[i] - 'a' + 1) * p^i) % m from i = 0 to n -1
 * where s is the key, p is a prime number greater than the input alphabet
 * m is the capacity of the table, n is the length of the key
 * The choosen alphabet is all lowercase letters
 * @param table
 * @param key
 * @return the hash
 */
int ht_get_hash(int capacity, char *key) {
    int p = 29;
    int m = capacity;
    int hash = 0;

    for(int i = 0; i < strlen(key); i++) {
        hash += (key[i] - 'a' + 1) * (int) pow(p, i);
    }
    return hash % m;
}

void ht_put(ht_table *table, char *key, char *data) {
    ht_item* item = ht_create_item(key, data);

    int index = ht_get_hash(table->capacity, key);

    while (table->items[index] != NULL) {
        ++index;
        index %= table->capacity;
    }

    table->items[index] = item;
    table->size++;
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
