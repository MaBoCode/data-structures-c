
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

q_queue *q_create(unsigned int capacity) {
	q_queue* queue = (q_queue*) malloc(sizeof(q_queue));

	if (queue == NULL) {
		fprintf(stderr, "Couldn't allocate memory for queue\n");
        exit(1);
	}

	if (capacity <= 0) {
		fprintf(stderr, "Unvalid capacity\n");
		return NULL;
	}

	queue->front = capacity - 1;
	queue->capacity = capacity;
	queue->size = 0;
	queue->items = (void**) malloc(capacity * sizeof(void*));

	if (queue->items == NULL) {
		fprintf(stderr, "Coudn't allocate memory for items\n");
		exit(1);
	}

	for (int i = 0; i < capacity; i++) {
		queue->items[i] = NULL;
	}
	return queue;
}

void q_add(q_queue *queue, void *value) {
	if (queue == NULL) {
		fprintf(stderr, "Can't add to NULL queue\n");
		return;
	}

	if (value == NULL) {
		fprintf(stderr, "Can't add NULL value\n");
		return;
	}

	if (queue->size == queue->capacity) {
		fprintf(stderr, "Queue is full\n");
		return;
	}

	for (int i = queue->capacity - 1; i >= 0; i--) {
		if (queue->items[i] == NULL) {
			queue->items[i] = value;
			break;
		}
	}
	queue->size++;
}

void *q_peek(q_queue *queue) {
	if (queue == NULL) {
		fprintf(stderr, "Can't peek to NULL queue\n");
		return;
	}

	if (queue->size == 0) {
		fprintf(stderr, "Queue is empty\n");
		return NULL;
	}

	return queue->items[queue->front];
}

void *q_poll(q_queue *queue) {
	return q_remove(queue);
}

void *q_remove(q_queue *queue) {
	if (queue == NULL) {
		fprintf(stderr, "Can't remove to NULL queue\n");
		return;
	}

	if (queue->size == 0) {
		fprintf(stderr, "Queue is empty\n");
		return NULL;
	}

	void *front = queue->items[queue->front];

	for (int i = queue->capacity - 2; i >= 0; i--) {
		queue->items[i+1] = queue->items[i];
	}
	queue->items[0] = NULL;
	queue->size--;
	return front;
}

int q_is_empty(q_queue *queue) {
	return queue->size == 0 ? 0 : -1;
}

void q_free(q_queue *queue) {
	free(queue->items);
	free(queue);
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
