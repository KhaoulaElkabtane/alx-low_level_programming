#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - that reads a text file and prints
 * @filename: variable pointer
 * @letters: size letters
 * Description: Write a function that reads a text file and prints it
 * to the POSIX standard output.
 * Return: the actual number of letters it could read and print, 0 otherwise
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fil, l, op;
	char *textfile;

	if (!filename)
	{
		return (0);
	}
	textfile = malloc(sizeof(char) * letters);
	if (textfile == NULL)
	{
		return (0);
	}

	op = open(filename, O_RDONLY);
	fil = read(op, textfile, letters);
      	l = write(STDOUT_FILENO, textfile, fil);

	if (op == -1 || fil == -1 || l == -1 || fil != l)
	{
		free(textfile);
		return (0);
	}
	free(textfile);
	close(op);
	return (l);
}
