/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spooooky_resolve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:24:24 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/31 12:35:49 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/spooooky.h"

int	ft_resolve(char grid[SIZE][SIZE], t_params *params)
{
	int	x;
	int	y;
	int	value;

	if (ft_search_empty_case(grid, &x, &y))
	{
		value = '0';
		while (++value <= (SIZE + '0'))
		{
			if (ft_can_put_value(grid, x, y, value))
			{
				grid[y][x] = value;
				if (x == (SIZE - 1) && !ft_line_is_valid(grid, params, y))
					continue ;
				if (y == (SIZE - 1) && !ft_column_is_valid(grid, params, x))
					continue ;
				if (ft_resolve(grid, params) == 1)
					return (1);
			}
		}
		grid[y][x] = 0;
		return (0);
	}
	return (1);
}

int	ft_search_empty_case(char grid[SIZE][SIZE], int *x, int *y)
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

int	ft_can_put_value(char grid[SIZE][SIZE], int x, int y, int value)
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