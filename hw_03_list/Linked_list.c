#define _CRT_SECURE_NO_WARNINGS
#include "Linked_list.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
print_linked_list(const list*head)
{
	while (head)
	{
		printf("%d", head->value);
		head = head->next;
	}
	printf("\n");
} 
list* get_end(list** head)
{
	list* l = *head;
	while (l->next)
	{
		l = l->next;
	}
	return (l);
}
add_first(list** head, int a)
{
	list* l = (list*)malloc(sizeof(list));
	l->value = a;
	l->next = *head;
	*head = l;
}
add_last(list* head, int a)
{
	list* l = get_end(head);
	list* last = (list*)malloc(sizeof(list));
	last->value = a;
	last->next = NULL;
	l->next = last;
}
add_N(list** head, int n, int a)
{
	int i = 0;
	list* tmp = NULL;
	list* l = *head;
	while ((i < n) && (l->next))
	{
		l = l->next;
		i++;
	}
	tmp = (list*)malloc(sizeof(list));
	tmp->value = a;
	if (l->next)
		tmp->next = l->next;
	else tmp->next = NULL;
	l->next = tmp;
}
delete_first(list** head)
{
	list* q = NULL;
	 q = *head;
	*head = (*head)->next;
	free(q);
}
delete_last(list** head)
{
	list* pF = NULL;
	list* pB = NULL;
	if (head==NULL) exit(-1);
	pF = *head;
	while (pF->next)
	{
		pB = pF;
		pF = pF->next;
	}
	if (pB == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		free(pF->next);
		pB->next = NULL;
	}
	
}
