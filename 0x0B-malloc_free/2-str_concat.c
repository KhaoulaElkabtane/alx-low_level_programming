#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: char*
 * @s2: char*
 * Return: pointer of char.
 */

char *str_concat(char *s1, char *s2)
{
	int i1 = 0;
	int i2 = 0;
	char *s;
	int i;

	if (s1 == NULL && s2 == NULL)
	{
		s = (char *) malloc(sizeof(char));
		*s = '\0';
		return (s);
	}
	if (s1 != NULL)
	{
		while (s1[i1] != '\0')
		{
			i1++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[i2] != '\0')
		{
			i2++;
		}
	}
	s = (char *) malloc((i1 + i2 + 1) * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < i1; i++)
	{
		s[i] = s1[i];
	}
	for (i = i1; i < i1 + i2; i++)
	{
		s[i] = s2[i - i1];
	}
	return (s);
}
