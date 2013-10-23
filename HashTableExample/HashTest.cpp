#include <assert.h>
#include "HashTable.h"

int main() {
	hash_table h = hash_table_create(7);

	hash_table_insert(h, 1, 2);
	hash_table_insert(h, 2, 3);
	hash_table_insert(h, 3, 4);
	hash_table_insert(h, 4, 5);
	hash_table_insert(h, 5, 6);
	hash_table_insert(h, 8, 9);

	int r = hash_table_retrieve(h, 8);

	assert(r == 9);

	return 0;
}