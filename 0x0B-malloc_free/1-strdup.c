#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - copy of a string
 * @str: char*
 * Return: pointer of char.
 */

char *_strdup(char *str)
{
	int i;
	int j;
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	s = (char *) malloc((i + 1) * sizeof(char));

	if (s == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		s[j] = str[j];
	}
	s[i] = '\0';
	return (s);
}
