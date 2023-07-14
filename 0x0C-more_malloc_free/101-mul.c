#include "main.h"
#include <stdlib.h>
#include <stdio.h>


#define ERR_MSG "Error"


/**
* is_digit - checks if a string contains a non-digit char
* @n: str to be evaluated
*
* Return: 0 if a non-digit is found, 1 otherwise
*/

int is_digit(char *n)
{
	int i = 0;

	while (n[i])
	{
		if (n[i] < '0' || n[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
* _strlen - returns the length of a string
* @n: string to evaluate
*
* Return: the length of the string
*/

int _strlen(char *n)
{
	int i = 0;

	while (n[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
* errors - handles errors for main
*/

void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
* main - multiplies two positive numbers
* @argc: number of arg
* @argv: array of arg
*
* Return: always 0 (Success)
*/

int main(int argc, char *argv[])
{
	char *n1, *n2;
	int l1, l2, l, i, carry, digit1, digit2, *result, a = 0;

	n1 = argv[1], n2 = argv[2];
	if (argc != 3 || !is_digit(n1) || !is_digit(n2))
		errors();
	l1 = _strlen(n1);
	l2 = _strlen(n2);
	l = l1 + l2 + 1;
	result = malloc(sizeof(int) * l);
	if (!result)
		return (1);
	for (i = 0; i <= l1 + l2; i++)
		result[i] = 0;
	for (l1 = l1 - 1; l1 >= 0; l1--)
	{
		digit1 = n1[l1] - '0';
		carry = 0;
		for (l2 = _strlen(n2) - 1; l2 >= 0; l2--)
		{
			digit2 = n2[l2] - '0';
			carry += result[l1 + l2 + 1] + (digit1 * digit2);
			result[l1 + l2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[l1 + l2 + 1] += carry;
	}
	for (i = 0; i < l - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
