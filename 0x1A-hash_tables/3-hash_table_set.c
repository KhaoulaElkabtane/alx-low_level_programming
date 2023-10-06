#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates a key-value pair in a hash table.
 * @ht: Pointer to the hash table.
 * @key: Key to add or update.
 * @value: Value associated with the key.
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *newnode;
	char *str;
	unsigned long int ig, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	str = strdup(value);
	if (str == NULL)
		return (0);

	ig = key_index((const unsigned char *)key, ht->size);
	for (i = ig; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = str;
			return (1);
		}
	}

	newnode = malloc(sizeof(hash_node_t));
	if (newnode == NULL)
	{
		free(str);
		return (0);
	}
	newnode->key = strdup(key);
	if (newnode->key == NULL)
	{
		free(newnode);
		return (0);
	}
	newnode->value = str;
	newnode->next = ht->array[ig];
	ht->array[ig] = newnode;

	return (1);
}
