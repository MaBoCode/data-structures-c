//
// Created by matt on 5/15/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

int getHash(int size, int key) {
    if(key < 0)
        return -(key % size);
    return key % size;
}

HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*) malloc(sizeof(HashMap));
    map->size = size;
    map->entries = (Entry**) malloc(sizeof(Entry) * size);

    for(int i = 0; i < size + 1; i++) {
        //(*(map->entries+i))->next = NULL;
        map->entries[i] = NULL;
    }
    return map;
}

void put(HashMap *map, int key, int value) {
    int pos = getHash(map->size, key);
    Entry *entries = map->entries[pos];
    Entry *temp = entries;
    Entry *nEntry = (Entry*) malloc(sizeof(Entry));

    while (temp) {
        if(temp->key == key) {
            temp->value = value;
            return;
        }
        temp = (Entry *) temp->next;
    }
    nEntry->key = key;
    nEntry->value = value;
    nEntry->next = entries;
    map->entries[pos] = nEntry;
    map->size++;
}

Entry* get(HashMap* map, int key) {
    int pos = getHash(map->size, key);
    Entry *entry = map->entries[pos];

    while(entry != NULL) {
        if(entry->key == key)
            return entry;
        entry = entry->next;
    }
    return NULL;
}

void printMap(HashMap *map) {
   Entry* temp = *map->entries;

   while (temp->next != NULL) {
       printf("key: %d, value: %d\n", temp->key, temp->value);
   }
}