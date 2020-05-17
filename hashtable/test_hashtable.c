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

    char* value1 = "test";
    char* value2 = "test2";
    char* value3 = "test3";

    HashTable* table = create_table_str(5);

    put_str(table, 0, value1);
    put_str(table, 1, value2);
    put_str(table, 1, value3);

    print_table(table);

    free(table);

    return 0;
}