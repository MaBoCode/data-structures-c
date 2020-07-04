
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

q_queue *q_create(unsigned int capacity) {
	q_queue *queue = (q_queue*) malloc(sizeof(q_queue));

	if (queue == NULL) {
		fprintf(stderr, "Couldn't allocate memory for queue\n");
        exit(1);
	}

	queue->front = capacity - 1;
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
			queue->items[i] = value;
			break;
		}
	}
}

int q_peek(q_queue *queue) {
	if (queue == NULL) {
		fprintf(stderr, "Can't peek to NULL queue\n");
		return;
	}

	return queue->items[queue->front];
}

int q_remove(q_queue *queue) {
	if (queue == NULL) {
		fprintf(stderr, "Can't remove to NULL queue\n");
		return;
	}

	int front = queue->items[queue->front];

	for (int i = queue->capacity - 2; i >= 0; i--) {
		queue->items[i+1] = queue->items[i];
	}
	queue->items[0] = NULL;
	return front;
}

void q_print(q_queue *queue) {

	for (int i = 0; i < queue->capacity - 1; i++) {
		if (queue->items[i] == NULL) {
			printf("NULL -> ");
		} else {
			printf("%d -> ", queue->items[i]);
		}
	}
	printf("%d\n", queue->items[queue->capacity-1]);
}
