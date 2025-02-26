#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_LEN	64

typedef struct ring_queue
{
	int front;
	int rear;
	int values[MAX_QUEUE_LEN];
} rq_t;

/** Initialize ring queue */
int rq_init(rq_t *q)
{
	if (!q) {
		return -1;
	}

	q->front = q->rear = -1;

	return 0;
}

/** Add to the end of ring queue */
int rq_enqueue(rq_t *q, int value)
{
	if (!q) {
		return -1;
	}

	if ((q->rear + 1) % (MAX_QUEUE_LEN) == q->front) {
		return -1;
	}

	q->rear = (q->rear + 1) % (MAX_QUEUE_LEN);
	q->values[q->rear] = value;

	if (q->front == -1)
		q->front = q->rear;

	return 0;
}

/** Remove a value from the front of ring queue & save it */
int rq_dequeue(rq_t *q, int *value)
{
	if (!q) {
		return -1;
	}

	if (q->front == -1) {
		return -1;
	}

	*value = q->values[q->front];
	
	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front = (q->front + 1) % (MAX_QUEUE_LEN);

	return 0;
}

int is_rq_empty(rq_t *q)
{
	if (q->front == -1)
		return 1;
	else
		return 0;
}

int is_rq_full(rq_t *q)
{
	if ((q->rear + 1) % (MAX_QUEUE_LEN) == q->front)
		return 1;
	else
		return 0;
}

void rq_display(rq_t *q)
{
	int i;

	if (!q) {
		printf("error: invalid pointer\n");
		return;
	}

	if (is_rq_empty(q)) {
		printf("Queue empty\n");
		return;
	}

	printf("Queue contents are : \n");

	i = q->front;

	while (i <= q->rear)
	{
		printf("%d ", q->values[i++]);
	}
	printf("\n");
}

int main(void)
{
	rq_t *q;
	int val;
	int index;

	q = (rq_t *)malloc(sizeof(rq_t));

	if (rq_init(q) == -1) {
		printf("Error in initializing the queue\n");
		return (-1);
	}

	for (index = 0; index < MAX_QUEUE_LEN; index++) {
		val = (index);
		rq_enqueue(q, val);
	}
	
	rq_display(q);
		
	val = (512);
	if (rq_enqueue(q, val) == -1)
		printf("Queue Full\n");

	printf("\n");
	for (index = 0; index < MAX_QUEUE_LEN; index++) {
		rq_dequeue(q, &val);
		printf("Dequed val is %d\n", val);	
	}
		
	if (rq_dequeue(q, &val) == -1)
		printf("\nQueue Empty\n");

	if (q) {
		free(q);
		q = NULL;
	}

	return(0);
}

