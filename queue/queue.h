#ifndef INT_QUEUE_H
#define INT_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node 
{
    struct queue_node * prev;
    int val;
    struct queue_node * next;
} q_node;

typedef struct q_queue
{
    int size;
    q_node * back;
    q_node * front;
} q_queue;

q_queue q_init();
void q_push_back(q_queue *q, int newVal);
int q_pop_front(q_queue *q);
void q_clear(q_queue *q);

#endif //INT_QUEUE_H
