//
// Created by Matthias Brown Marie on 28/04/2020.
//

#ifndef HASH_TABLE_HASHTABLE_H
#define HASH_TABLE_HASHTABLE_H

#define SIZE 20

typedef struct {
    int key;
    int data;
} ItemInt;

typedef struct {
    int key;
    char* data;
} ItemStr;

typedef struct {
    int size;
    void **items;
} HashTable;

HashTable* create_table_int(int size);
HashTable* create_table_str(int size);

int get_hash(int key);

void put_int(HashTable* table, int key, int data);
void put_str(HashTable* table, int key, char* data);

void* get(HashTable* table, int key);

ItemInt* delete_int(HashTable* table, ItemInt* item);

void print_item_int(ItemInt *item);
void print_item_str(ItemStr* item);

void print_table(HashTable* table);
#endif //HASH_TABLE_HASHTABLE_H
