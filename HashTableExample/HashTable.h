#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "list.h"

typedef struct {
	unsigned int table_size;
	unsigned int num_elements;
	list *table;
} HASH_TABLE;

typedef HASH_TABLE* hash_table;

hash_table hash_table_create(unsigned int table_size);
void hash_table_insert(hash_table h, int key, int value);
int hash_table_retrieve(hash_table h, int key);
void hash_table_destroy(hash_table h);

#endif