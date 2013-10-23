#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list list_create()
{
	list l = (list) malloc(sizeof(node));
	l->next = NULL;
	return l;
}

void list_insert_back(list l, pair p)
{
	node *n = (node*) malloc(sizeof(node));
	if (!n)
		printf("Out of memory! Uhh... what now?\n");
	else
	{
		n->data = p;
		n->next = NULL;
		// go to the end of the list
		while (l->next)
			l = l->next;
		l->next = n;
	}
}

bool list_delete(list l, int k)
{
	node *prev = find_prev(l, k);
	if (prev)
	{
		node *target = prev->next;
		prev->next = target->next;
		free(target);
		return true;
	}
	else
		return false;
}

node* find_prev(list l, int k)
{
	node *prev = l;
	while (prev->next && prev->next->data.key != k)
		prev = prev->next;

	return prev->next ? prev : NULL;
}

node* list_search(list l, int k)
{
	node *prev = find_prev(l, k);
	
	return prev ? prev->next : NULL;
}

void list_print(list l)
{
	while (l = l->next)
		printf("%d,%d ", l->data.key, l->data.value);
	printf("\n");
}

void list_destroy(list l)
{
	node *tmp = NULL;
	while (l)
	{
		tmp = l;
		l = l->next;
		free(tmp);
	}
	free(tmp);
}