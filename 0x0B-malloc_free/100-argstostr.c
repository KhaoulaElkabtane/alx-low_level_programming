#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program
 *@ac: number of arguments
 *@av: arguments
 * Return: a pointer to a new string
 */
char *argstostr(int ac, char **av)
{
	int i;
	int j;
	char *p = NULL;
	int k;
	int esc;

	k = 0;
	esc = 0;
	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			esc++;
		}
	}

	p = (char *)malloc(esc + ac + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			p[k] = av[i][j];
			k++;
		}
		p[k] = '\n';
		k++;
	}
	p[k] = '\0';
	return (p);
}
