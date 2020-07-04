
#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
	int front;
	unsigned int capacity;
	int *items;
} q_queue;

q_queue *q_create(unsigned int capacity);

void q_add(q_queue *queue, int value);

int q_peek(q_queue *queue);

int q_remove(q_queue *queue);

void q_print(q_queue *queue);

#endif
