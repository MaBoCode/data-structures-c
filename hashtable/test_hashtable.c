#include <stdio.h>
#include "hashtable.h"

int main(void) {

    char* key1 = "key";
    char* key2 = "akey";
    char* key3 = "anotherkey";

    char* value1 = "data";
    char* value2 = "avalue";
    char* value3 = "anothervalue";

    ht_table *table = ht_create_table(2);

    printf("hash for %s is %d\n", key1, ht_get_hash(table->capacity, key1));
    printf("hash for %s is %d\n", key2, ht_get_hash(table->capacity, key2));
    printf("hash for %s is %d\n", key3, ht_get_hash(table->capacity, key3));

    ht_put(table, key1, value1);
    ht_put(table, key2, value2);
    ht_put(table, key3, value3);

    printf("value for %s is %s\n", key1, ht_get(table, key1)->data);
    printf("value for %s is %s\n", key2, ht_get(table, key2)->data);
    printf("value for %s is %s\n", key3, ht_get(table, key3)->data);

    ht_delete_table(table);
    return 0;
}