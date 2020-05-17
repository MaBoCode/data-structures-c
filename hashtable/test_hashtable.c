#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hashtable.h"

#define TABLE_SIZE 2069

int* letter_occur(char* string) {

    static int letter_occur_table[26] = {0};

    for (int i = 0; i < strlen(string); i++) {
        int index = string[i] - 'a';
        if(index >= 0 && index < 26) {
            letter_occur_table[index] += 1;
        }
    }
    return letter_occur_table;
}

int main(void) {

    char* key1 = "key";
    char* key2 = "akey";
    char* key3 = "anotherkey";

    char* value1 = "value";
    char* value2 = "avalue";
    char* value3 = "anothervalue";

    ht_table *table = ht_create_table(53);

    ht_put(table, key1, value1);
    ht_put(table, key2, value2);
    ht_put(table, key3, value3);

    ht_print_table(table);

    ht_delete_table(table);
    return 0;
}