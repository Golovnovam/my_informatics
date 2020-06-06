
#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct node
{
	float value;
	struct node* next;
	struct node* back;
}node;

typedef struct queue
{
	float data;
	struct node* head;
	struct node* tail;
}queue;

enqueue(struct queue* queue, const float value);
dequeue(struct queue* queue);
#endif 