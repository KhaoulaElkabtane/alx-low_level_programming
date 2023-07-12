#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * alloc_grid - allocate a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i;
	int j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	grid = (int **) malloc((width - 1) * sizeof(int *));
	if (grid == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < width; i++)
	{
		grid[i] = (int *) malloc((height - 1) * sizeof(int));
		if (grid[i] == NULL)
		{
			return (NULL);
		}
	}
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			grid[i][j] = 0;
		}
	}
	return (grid);
}
