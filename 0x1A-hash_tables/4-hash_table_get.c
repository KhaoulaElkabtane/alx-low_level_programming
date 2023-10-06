#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key in a hash table.
 * @ht: Pointer to the hash table.
 * @key: Key to search for.
 * Return: The value associated with the key, or NULL if key not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *hash;
	unsigned long int ig;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	ig = key_index((const unsigned char *)key, ht->size);
	if (ig >= ht->size)
		return (NULL);

	hash = ht->array[ig];
	while (hash && strcmp(hash->key, key) != 0)
		hash = hash->next;

	return ((hash == NULL) ? NULL : hash->value);
}
