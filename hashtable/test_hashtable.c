#include "hashtable.h"

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

    ht_delete_table(table);
    return 0;
}