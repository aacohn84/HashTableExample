# ifndef _LIST_H
# define _LIST_H

typedef struct {
	int key;
	int value;
} pair;

typedef struct NODE
{
	pair data;
	NODE *next;
} node;

typedef node* list;

list list_create();
void list_insert_back(list l, pair v);
bool list_delete(list l, int key);
node* find_prev(list l, int key);
node* list_search(list l, int key);
void list_print(list l);
void list_destroy(list l);

# endif