
#include <unistd.h>
#include "spooky.h"

int	g_i;

int	column_is_valid (char grid[SIZE][SIZE], t_params *params, int x)
{
	int	max_size;
	int	views;

	max_size = 0;
	views = 0;
	g_i = -1;
	while (++g_i < SIZE)
	{
		views += grid[g_i][x] > max_size;
		if (grid[g_i][x] > max_size)
			max_size = grid[g_i][x];
	}
	if (views != params -> up[x])
		return (0);
	max_size = 0;
	views = 0;
	while (--g_i >= 0)
	{
		views += grid[g_i][x] > max_size;
		if (grid[g_i][x] > max_size)
			max_size = grid[g_i][x];
	}
	if (views != params -> down[x])
		return (0);
	return (1);
}

int	line_is_valid(char grid[SIZE][SIZE], t_params *params, int y)
{
	int	max_size;
	int	views;

	max_size = 0;
	views = 0;
	g_i = -1;
	while (++g_i < SIZE)
	{
		views += grid[y][g_i] > max_size;
		if (grid[y][g_i] > max_size)
			max_size = grid[y][g_i];
	}
	if (views != params -> left[y])
		return (0);
	max_size = 0;
	views = 0;
	while (--g_i >= 0)
	{
		views += grid[y][g_i] > max_size;
		if (grid[y][g_i] > max_size)
			max_size = grid[y][g_i];
	}
	if (views != params -> right[y])
		return (0);
	return (1);
}

int	can_put_value(char grid[SIZE][SIZE], int x, int y, int value)
{
	int	i;

	i = -1;
	while (++i < SIZE)
	{
		if (grid[y][i] == value || grid[i][x] == value)
			return (0);
	}
	return (1);
}

int 	search_empty_case(char grid[SIZE][SIZE], int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			if (grid[i][j] == 0)
			{
				*x = j;
				*y = i;
				return (1);
			}
		}
	}
	return (0);
}