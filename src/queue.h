
#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
	int front;
	unsigned int size;
	unsigned int capacity;
	void **items;
} q_queue;

q_queue *q_create(unsigned int capacity);

void q_add(q_queue *queue, void *value);

void *q_peek(q_queue *queue);

void *q_poll(q_queue *queue);

void *q_remove(q_queue *queue);

int q_is_empty(q_queue *queue);

void q_print(q_queue *queue);

#endif
