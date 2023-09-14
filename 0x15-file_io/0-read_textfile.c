<<<<<<< HEAD
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
=======
/*
 * File: 0-read_textfile.c
 * Auth: Dr Marcus.
 */
#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
>>>>>>> 74cf82cf048581139b8d714721547884c1a7aad0
}
