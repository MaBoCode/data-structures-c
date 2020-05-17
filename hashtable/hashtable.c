//
// Created by Matthias Brown Marie on 28/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

HashTable *create_table_int(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));

    if(table == NULL) {
        fprintf(stderr, "Couldn't allocate memory for table.\n");
        exit(1);
    }

    table->size = size;
    table->items = (void **) calloc(size, sizeof(ItemInt));

    return table;
}

HashTable *create_table_str(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));

    if(table == NULL) {
        fprintf(stderr, "Couldn't allocate memory for table.\n");
        exit(1);
    }

    table->size = size;
    table->items = (void **) calloc(size, sizeof(ItemStr));

    return table;
}

int get_hash(int key) {
    return key % SIZE;
}

void put_int(HashTable* table, int key, int data) {
    ItemInt* item = (ItemInt*) malloc(sizeof(ItemInt));
    item->key = key;
    item->data = data;

    int index = get_hash(key);

    while (table->items[index] != NULL) {
        ++index;
        index %= table->size;
    }

    table->items[index] = item;
}

void put_str(HashTable *table, int key, char *data) {
    ItemStr* item = (ItemStr*) malloc(sizeof(ItemStr));
    item->key = key;
    item->data = data;

    int index = get_hash(key);

    while (table->items[index] != NULL) {
        ++index;
        index %= table->size;
    }

    table->items[index] = item;
}

void* get(HashTable* table, int key) {
    int index = get_hash(key);

    while (table->items[index] != NULL) {
        if(((ItemInt*)(table->items[index]))->key == key)
            return table->items[index];
        ++index;
        index %= table->size;
    }
    return NULL;
}

ItemInt* delete_int(HashTable* table, ItemInt* item) {
    int index = get_hash(item->key);

    while (table->items[index] != NULL) {
        ItemInt* current_item = (ItemInt*) table->items[index];

        if(current_item->key == item->key) {
            table->items[index] = NULL;
            table->size--;
            return current_item;
        }
    }
    return NULL;
}

int containsKey(HashTable* table, int key) {
    int index = get_hash(key);

    while (table->items[index] != NULL) {
        ItemInt* current_item = (ItemInt*) table->items[index];
        if(current_item->key == key)
            return 0;
        ++index;
        index %= table->size;
    }

    return 1;
}

void print_item_int(ItemInt* item) {
    printf("key = %d, data = %d\n", item->key, item->data);
}

void print_item_str(ItemStr* item) {
    printf("key = %d, data = %s\n", item->key, item->data);
}

void print_table(HashTable* table) {
    for (int i = 0; i < table->size; ++i) {
        print_item_str(table->items[i]);
    }
}