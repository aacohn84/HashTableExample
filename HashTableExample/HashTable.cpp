#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>

const int TABLE_SIZE_MIN = 7;

hash_table hash_table_create(unsigned int table_size) {
	if (table_size < TABLE_SIZE_MIN) {
		table_size = TABLE_SIZE_MIN;
	}
	hash_table h = (hash_table) malloc(sizeof(HASH_TABLE));
	h->table_size = table_size;
	h->num_elements = 0;
	h->table = (list*) calloc(table_size, sizeof(list));
	for (unsigned int i = 0; i < table_size; i++) {
		h->table[i] = NULL;
	}

	return h;
}

int prehash(int key, unsigned int table_size) {
	return key % table_size; // TODO: improve the hash function
}

void hash_table_grow(hash_table h) {
	// do nothing for now
}

void hash_table_insert(hash_table h, int key, int value) {
	if (h->num_elements >= h->table_size) {
		hash_table_grow(h);
	}
	pair p = {key, value};
	int i = prehash(key, h->table_size);
	if (h->table[i] == NULL) {
		h->table[i] = list_create();
	}
	list_insert_back(h->table[i], p);
	h->num_elements++;
}

int hash_table_retrieve(hash_table h, int key) {
	int i = prehash(key, h->table_size);
	node *item = list_search(h->table[i], key);
	return item->data.value;
}

void hash_table_destroy(hash_table h) {
	for (int i = h->table_size; i > 0; i--) {
		list_destroy(h->table[i-1]);
	}
}
