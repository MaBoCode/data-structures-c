#include <stdio.h>
#include "hashtable.h"

int main(void) {

	ht_table *table = ht_create_table(3);

	if (ht_is_empty(table) == 0) {
		printf("Table is empty\n");
	}

	ht_put(table, "key1", "data1");
	ht_put(table, "key2", "data2");
	ht_put(table, "key3", "data3");
	ht_put(table, "key4", "data4");
	ht_put(table, "key5", "data5");
	ht_put(table, "key6", "data6");
	ht_put(table, "key7", "data7");

	if (ht_is_empty(table) == -1) {
		printf("Table not empty\n");
	}

	printf("sizeof items = %d\n", sizeof(table->items));

	ht_print_table(table);

	char **keys = ht_keys(table);

	for (int i = 0; i < table->capacity; i++) {
		printf("key=%s\n", keys[i]);
	}

	printf("Removing value %s\n", ht_remove(table, "key4"));

	ht_print_table(table);

	printf("Removing value %s\n", ht_remove(table, "key1"));

	ht_print_table(table);

	printf("Clearing table...\n");
	ht_clear(table);

	printf("%d items in table\n", table->size);

	ht_print_table(table);

	printf("sizeof items = %d\n", sizeof(table->items));

	ht_put(table, "key1", "data1");

	ht_print_table(table);

	if (ht_contains_key(table, "key1") == 0) {
		printf("Table contains key1\n");
	}

	if (ht_contains_value(table, "data1") == 0) {
		printf("Table contains data1\n");
	}

	printf("Replacing %s by %s\n", ht_replace(table, "key1", "data2"), "data2");

	ht_print_table(table);

    return 0;
}
