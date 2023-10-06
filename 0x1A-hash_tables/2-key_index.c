#include "hash_tables.h"

/**
 * key_index - Computes the index of a key in a hash table.
 * @key: Input key (string) for which to compute the index.
 * @size: Size of the hash table.
 * Return: The index of the key in the hash table.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
