#include <stdio.h>
#include "hashtable.h"

int main(void) {

    char* key1 = "key1";
    char* key2 = "key2";
    char* key3 = "key3";
    char* key4 = "key4";

    char* value1 = "zegzg";
    char* value2 = "zegrggtyh";
    char* value3 = "vth";
    char* value4 = "vrthrtjjrgerghetherh";

    ht_table *table = ht_create_table(4);

    ht_put(table, key1, value1);
    ht_put(table, key2, value2);
    ht_put(table, key3, value3);
    ht_put(table, key4, value4);

    ht_print_table(table);
    ht_delete_table(table);
    return 0;
}