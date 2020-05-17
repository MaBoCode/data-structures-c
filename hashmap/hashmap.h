//
// Created by matt on 5/15/20.
//

#ifndef HASH_TABLE_HASHMAP_H
#define HASH_TABLE_HASHMAP_H

#define MAX_SIZE 1024

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

//Entry default_entry = {.next = NULL};

typedef struct {
    int size;
    Entry** entries;
} HashMap;

int getHash(int map_size, int key);

HashMap* createHashMap(int);
void put(HashMap* map, int key, int value);
Entry* get(HashMap* map, int key);

void printMap(HashMap* map);

#endif //HASH_TABLE_HASHMAP_H
