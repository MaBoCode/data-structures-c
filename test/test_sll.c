//
// Created by matt on 5/17/20.
//

void test_sl() {
	sl_list *list = sl_create_list();
	sl_add(list, "5");
	sl_add(list, "4");
	sl_add(list, "7");
	sl_add(list, "9");
	sl_add(list, "-3");
	sl_add(list, "1");
	sl_add(list, "6");
	sl_add(list, "4");
	sl_add(list, "-5");
	sl_print_list(list);

	printf("Adding \"%s\" at %d\n", "test", 2);
	sl_add_at(list, 2, "test");
	sl_print_list(list);

	const char *data = sl_get(list, 2);
	printf("Element at %d is %s\n", 2, data);

	printf("Removing %s\n", "9");
	sl_remove(list, "9");
	sl_print_list(list);

	printf("Removing at %d\n", 0);
	sl_remove_at(list, 0);
	sl_print_list(list);

	const char *elem1 = "4";
	printf("Index of %s is %d\n", elem1, sl_index_of(list, elem1));
	printf("Last index of %s is %d\n", elem1, sl_last_index_of(list, elem1));

	const char *elem2 = "13";
	if(sl_contains(list, elem2) == 0) {
		printf("Contains %s\n", elem2);
	} else {
		printf("Doesn't contain %s\n", elem2);
	}

	if(sl_is_empty(list) == 0) {
		printf("List is empty\n");
	} else {
		printf("List is not empty\n");
	}

	const char *elem3 = "kablemo";
	printf("Setting element at %d to %s\n", 3, elem3);
	sl_set(list, 3, elem3);
	sl_print_list(list);

	printf("Removing all elements\n");
	sl_remove_all(list);
	if(sl_is_empty(list) == 0) {
		printf("List is empty\n");
	} else {
		printf("List is not empty\n");
	}
	printf("Size = %lu\n", list->size);
}
