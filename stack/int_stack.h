#ifndef INT_STACK_H
#define INT_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define bool char
#define true 1
#define false 0

typedef struct IntNode
{
    int val;
    struct IntNode * next;
} IntNode;

typedef struct {
    size_t size;
    IntNode *top;
} IntStack;

bool init_intStack(IntStack * stack);
void pushInt(IntStack * stack, int newVal);
int popInt(IntStack * stack);
void clear_intStack(IntStack * stack);

#endif //INT_STACK_H
