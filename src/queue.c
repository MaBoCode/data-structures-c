
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

q_queue *q_create(unsigned int capacity) {
	q_queue *queue = (q_queue*) malloc(sizeof(q_queue));
	queue->front = NULL;
	queue->capacity = capacity;
	queue->items = malloc(capacity * sizeof(int));
	for (int i = 0; i < capacity; i++) {
		queue->items[i] = NULL;
	}
	return queue;
}

void q_add(q_queue *queue, int value) {
	if (queue == NULL) {
		fprintf(stderr, "Can't add to NULL queue\n");
		return;
	}

	for (int i = queue->capacity - 1; i >= 0; i--) {
		if (queue->items[i] == NULL) {
			printf("is null\n", );
		}
	}
}
