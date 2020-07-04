#include "queue.h"

#define NULL (void*) 0

int main(void) {

	q_queue *queue = q_create(3);

	q_add(queue, 1);
	q_add(queue, 2);
	q_add(queue, 3);

	q_print(queue);

	int front = q_remove(queue);

	printf("Front of queue is %d\n", front);

	q_print(queue);
}
