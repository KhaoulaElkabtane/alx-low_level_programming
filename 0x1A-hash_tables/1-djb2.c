#include "hash_tables.h"

/**
 * hash_djb2 - Implements the djb2 hashing algorithm.
 * @str: Input string to be hashed.
 * Return: The hash value of the input string.
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
