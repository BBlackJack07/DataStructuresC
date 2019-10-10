#include "queue.h"

static q_node* q_new_node(q_node* prev, int val, q_node* next) {
    q_node* newNode = malloc(sizeof(q_node));
    newNode->prev = prev;
    newNode->val  = val;
    newNode->next = next;
    return newNode;
}

q_queue q_init()
{
    q_queue queue;
    queue.back = NULL;
    queue.front = NULL;
    return queue;
}

int q_pop_front(q_queue *q)
{
    if (q->back == NULL)  { return -1; }
    if (q->front == NULL) { return -1; }

    int ret_val = q->front->val;
    if (q->front == q->back)
    {
        free(q->front);
        q->back = NULL;
        q->front = NULL;
    }
    else
    {
        q->front = q->front->prev;
        free(q->front->next);
        q->front->next = NULL;
    }
    q->size--;
    return ret_val;
}

void q_push_back(q_queue *q, int newVal)
{
    if (q == NULL) { return; }

    q_node* newback = q_new_node(NULL, newVal, q->back);
    if (q->back == NULL)
    {
        q->front = newback;
    }
    else
    {
        q->back->prev = newback;
    }
    q->back = newback;
    q->size++;
}

void q_clear(q_queue *q)
{
    while(q->back != NULL) {
        q_pop_front(q);
    } 
}


