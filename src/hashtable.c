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
    table->items = malloc(sizeof(ht_item*) * table->capacity);

    for(int i = 0; i < table->capacity; i++)
        table->items[i] = NULL;

    return table;
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
    unsigned int key_length = strlen(key);

    for(int i = 0; i < key_length; ++i) {
        hash += (key[i] * (int) pow(p, i)) ;
    }
    return hash % m;
}

void ht_put(ht_table *table, const char *key, const char *data) {
    unsigned int index = ht_get_hash(table->capacity, key);

    ht_item *item = table->items[index];

    if(item == NULL) {
        table->items[index] = ht_create_item(key, data);
        table->size++;
        return;
    }

    ht_item *prev_item = NULL;

    while (item != NULL) {
        if(strcmp(item->key, key) == 0) {
            free(item->data);
            item->data = strdup(data);
            return;
        }

        prev_item = item;
        item = prev_item->next;
    }

    //Handling hash collisions
    prev_item->next = ht_create_item(key, data);
    table->size++;
}

char *ht_get(ht_table *table, const char *key) {
    unsigned int index = ht_get_hash(table->capacity, key);

    ht_item *item = table->items[index];

    if(item == NULL) {
        return NULL;
    }

    while (item != NULL) {
        if(strcmp(item->key, key) == 0) {
            return  item->data;
        }
        item = item->next;
    }

    return NULL;
}

char *ht_remove(ht_table *table, const char *key) {
	unsigned int index = ht_get_hash(table->capacity, key);

	ht_item *tmp = table->items[index];

	if (tmp == NULL) {
		fprintf(stderr, "Key %s doesn't exist\n", key);
		return NULL;
	}

	char *data;

	if (strcmp(tmp->key, key) == 0) {
		//Removing first element in linked list
		table->items[index] = tmp->next;
		data = strdup(tmp->data);
		ht_delete_item(table, tmp);
		return data;
	}

	ht_item *prev;

	while (tmp != NULL) {
		if (strcmp(tmp->key, key) == 0) {
			data = strdup(tmp->data);
			prev->next = tmp->next;
			ht_delete_item(table, tmp);
			return data;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return NULL;
}

void ht_clear(ht_table *table) {
	if (table == NULL || table->items == NULL) {
		return;
	}

	printf("capacity: %d\n", table->capacity);

	for (int i = 0; i < table->capacity; i++) {
		ht_item *tmp = table->items[i];
		ht_item *next;

		while (tmp != NULL) {
			next = tmp->next;
			table->items[i] = NULL;
			ht_delete_item(table, tmp);
			tmp = next;
		}
	}
}

int ht_is_empty(ht_table *table) {

	if (table == NULL) {
		fprintf(stderr, "Table is null\n");
		return -1;
	}

	if (table->size == 0) {
		return 0;
	}
	return -1;
}

int ht_contains_key(ht_table *table, const char *key) {

	if (table == NULL) {
		fprintf(stderr, "Table is null\n");
		return -1;
	}

	unsigned int index = ht_get_hash(table->capacity, key);

	ht_item *tmp = table->items[index];

	while (tmp != NULL) {
		if (strcmp(tmp->key, key) == 0) {
			return 0;
		}
		tmp = tmp->next;
	}
	return -1;
}

int ht_contains_value(ht_table *table, const char *value) {

	if (table == NULL) {
		fprintf(stderr, "Table is null\n");
		return -1;
	}

	for (int i = 0; i < table->capacity; i++) {
		ht_item *tmp = table->items[i];

		while (tmp != NULL) {
			if (strcmp(tmp->data, value) == 0) {
				return 0;
			}
			tmp = tmp->next;
		}
	}
	return -1;
}

const char *ht_replace(ht_table *table, const char *key, const char *data) {

	if (table == NULL) {
		fprintf(stderr, "Table is null\n");
		return NULL;
	}

	if (key == NULL) {
		fprintf(stderr, "key is null\n");
		return NULL;
	}

	if (data == NULL) {
		fprintf(stderr, "data is null\n");
		return NULL;
	}

	unsigned int index = ht_get_hash(table->capacity, key);

	ht_item *tmp = table->items[index];
	const char *old_value = strdup(tmp->data);

	free(tmp->data);
	tmp->data = strdup(data);

	return old_value;
}

char **ht_keys(ht_table *table) {

	if (table == NULL) {
		fprintf(stderr, "Table is null\n");
		return NULL;
	}

	char **keys = calloc(table->capacity, sizeof(char*));

	for (int i = 0; i < table->capacity; i++) {
		ht_item *item = table->items[i];

		//TODO: return an array of array of char* of size table->capacity

		if (item != NULL) {
			keys[i] = strdup(item->key);
		} else {
			keys[i] = strdup("");
		}
	}
	return keys;
}

void ht_delete_item(ht_table* table, ht_item *item) {
    free(item->key);
	free(item->data);
	item->key = NULL;
	item->data = NULL;
	//free(item);
    table->size--;
}

void ht_delete_table(ht_table *table) {
    for(int i = 0; i < table->capacity; i++) {
        ht_item *item = table->items[i];
        if(item != NULL)
            ht_delete_item(table, item);
    }

    free(table->items);
    free(table);
}

void ht_print_item(ht_table *table, const char *key) {
    char *data = ht_get(table, key);
    printf("%s: %s\n", key, data);
}

void ht_print_table(ht_table *table) {
    for (int i = 0; i < table->capacity; i++) {
        ht_item *item = table->items[i];

        printf("[%d]: ", i);

        while (item != NULL) {
            printf("%s: %s ", item->key, item->data);
            item = item->next;
        }
        printf("\n");
    }
}
