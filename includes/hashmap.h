//
// Created by matt on 5/15/20.
//

#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    int size;
    Entry** entries;
} HashMap;

int getHash(int map_size, int key);

HashMap* createHashMap(int);
void put(HashMap* map, int key, int value);
Entry* get(HashMap* map, int key);

void printMap(HashMap* map);

#endif //HASHMAP_H
