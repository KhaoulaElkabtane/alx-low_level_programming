#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table with a given size.
 * @size: Size of the hash table.
 *
 * Return: A pointer to the created hash table, or NULL if it fails.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *var;
	unsigned long int i;

	var = malloc(sizeof(hash_table_t));
	if (var == NULL)
		return (NULL);

	var->size = size;
	var->array = malloc(sizeof(hash_node_t *) * size);
	if (var->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		var->array[i] = NULL;

	return (var);
}
