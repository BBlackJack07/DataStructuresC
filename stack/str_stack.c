#include "str_stack.h"

nodeStr* init_strStack(char* firstStr)
{
    nodeStr* head = (nodeStr*)malloc(sizeof(nodeStr));
    if (head == NULL)
        return NULL;
    head->next = NULL;
    head->str = firstStr;
    return head;
}

char* popStr(nodeStr **head) {
    if (*head == NULL)
        return "";
    nodeStr* newHead = (*head)->next;
    char* ret_str = (*head)->str;
    free(*head);
    *head = newHead;
    return ret_str;
}

void pushStr(nodeStr **head, char newStr[])
{
    if (*head != NULL)
    {
        nodeStr* newHead = (nodeStr*)malloc(sizeof(nodeStr));
        if (newHead != NULL)
        {
            newHead->next = (*head);
            newHead->str = newStr;
            *head = newHead;
        }
    }
}

void clear_strStack(nodeStr **head)
{
    while(*head != NULL)
        popStr(head);
}

void print(nodeStr *head)
{
    nodeStr *current = head;
	while (current->next != NULL)
	{
	    printf("%s\n", current->str);
		current = current->next;
    }

	printf("%s\n", current->str);
}
