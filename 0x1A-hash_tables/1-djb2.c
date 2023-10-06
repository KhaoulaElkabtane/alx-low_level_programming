#include "hash_tables.h"

/**
 * hash_djb2 - Hash function implementing the djb2 algorithm.
 * @str: The string to hash.
 *
 * Return: The calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int var;
	int ig;

	var = 5381;
	while ((ig = *str++))
		var = ((var << 5) + var) + ig;

	return (var);
}
