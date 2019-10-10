#ifndef STR_STACK_H
#define STR_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStr
{
    char* str;
    struct nodeStr * next;
} nodeStr;

nodeStr* init_strStack(char* firstStr);
void pushStr(nodeStr **head, char* newStr);
char* popStr(nodeStr **head);
void clear_strStack(nodeStr **head);
void print(nodeStr *head);

#endif //STR_STACK_H
