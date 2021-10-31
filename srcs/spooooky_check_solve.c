/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spooooky_check_solve.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:35:07 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/31 13:27:49 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/spooooky.h"

int	ft_column_is_valid(char grid[SIZE][SIZE], t_params *params, int x)
{
	int	max_size;
	int	views;

	max_size = 0;
	views = 0;
	params->i = -1;
	while (++params->i < SIZE)
	{
		views += grid[params->i][x] > max_size;
		if (grid[params->i][x] > max_size)
			max_size = grid[params->i][x];
	}
	if (views != params->up[x])
		return (0);
	max_size = 0;
	views = 0;
	while (--params->i >= 0)
	{
		views += grid[params->i][x] > max_size;
		if (grid[params->i][x] > max_size)
			max_size = grid[params->i][x];
	}
	if (views != params->down[x])
		return (0);
	return (1);
}

int	ft_line_is_valid(char grid[SIZE][SIZE], t_params *params, int y)
{
	int	max_size;
	int	views;

	max_size = 0;
	views = 0;
	params->i = -1;
	while (++params->i < SIZE)
	{
		views += grid[y][params->i] > max_size;
		if (grid[y][params->i] > max_size)
			max_size = grid[y][params->i];
	}
	if (views != params -> left[y])
		return (0);
	max_size = 0;
	views = 0;
	while (--params->i >= 0)
	{
		views += grid[y][params->i] > max_size;
		if (grid[y][params->i] > max_size)
			max_size = grid[y][params->i];
	}
	if (views != params -> right[y])
		return (0);
	return (1);
}
