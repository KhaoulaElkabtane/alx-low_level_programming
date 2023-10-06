#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: Size of the hash table.
 * Return: Pointer to the created sorted hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shah;
	unsigned long int i;

	shah = malloc(sizeof(shash_table_t));
	if (shah == NULL)
		return (NULL);

	shah->size = size;
	shah->array = malloc(sizeof(shash_node_t *) * size);
	if (shah->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		shah->array[i] = NULL;
	shah->shead = NULL;
	shah->stail = NULL;

	return (shah);
}

/**
 * shash_table_set - Adds or updates a key-value pair in a sorted hash table.
 * @ht: Pointer to the sorted hash table.
 * @key: Key to add or update.
 * @value: Value associated with the key.
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *newnode, *tmp;
	char *str;
	unsigned long int ig;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	str = strdup(value);
	if (str == NULL)
		return (0);

	ig = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = str;
			return (1);
		}
		tmp = tmp->snext;
	}

	newnode = malloc(sizeof(shash_node_t));
	if (newnode == NULL)
	{
		free(str);
		return (0);
	}
	newnode->key = strdup(key);
	if (newnode->key == NULL)
	{
		free(str);
		free(newnode);
		return (0);
	}
	newnode->value = str;
	newnode->next = ht->array[ig];
	ht->array[ig] = newnode;

	if (ht->shead == NULL)
	{
		newnode->sprev = NULL;
		newnode->snext = NULL;
		ht->shead = newnode;
		ht->stail = newnode;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		newnode->sprev = NULL;
		newnode->snext = ht->shead;
		ht->shead->sprev = newnode;
		ht->shead = newnode;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		newnode->sprev = tmp;
		newnode->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = newnode;
		else
			tmp->snext->sprev = newnode;
		tmp->snext = newnode;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with
 * a key in a sorted hash table.
 * @ht: Pointer to the sorted hash table.
 * @key: Key to search for.
 * Return: Value associated with the key,
 * or NULL if key is not found or on failure.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *shah;
	unsigned long int ig;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	ig = key_index((const unsigned char *)key, ht->size);
	if (ig >= ht->size)
		return (NULL);

	shah = ht->shead;
	while (shah != NULL && strcmp(shah->key, key) != 0)
		shah = shah->snext;

	return ((shah == NULL) ? NULL : shah->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(head->array);
	free(head);
}
