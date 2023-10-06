#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and its contents.
 * @ht: Pointer to the hash table to be deleted.
 * Return: Nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *hsh = ht;
	hash_node_t *hash, *tmp;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			hash = ht->array[i];
			while (hash != NULL)
			{
				tmp = hash->next;
				free(hash->key);
				free(hash->value);
				free(hash);
				hash = tmp;
			}
		}
	}
	free(hsh->array);
	free(hsh);
}
