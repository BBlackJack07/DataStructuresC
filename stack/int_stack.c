#include "int_stack.h"

bool init_intStack(IntStack * stack)
{
    if (stack == NULL)
        return false;
    stack->top = NULL;
    stack->size = (size_t)0;
    return true;
}

int popInt(IntStack * stack)
{
    if (stack == NULL || stack->top == NULL)
        return -1;
    IntNode* newHead = stack->top->next;
    int ret_val = stack->top->val;
    free(stack->top);
    stack->top = newHead;
    stack->size--;
    return ret_val;
}

void pushInt(IntStack * stack, int newVal)
{
    if (stack != NULL)
    {
        IntNode* newHead = (IntNode*)malloc(sizeof(IntNode));
        if (newHead != NULL)
        {
            newHead->next = stack->top;
            newHead->val = newVal;
            stack->top = newHead;
            stack->size++;
        }
    }
}

void clear_intStack(IntStack * stack)
{
    if (stack != NULL)
    {
        while(stack->top != NULL)
            popInt(stack);
    }
}


