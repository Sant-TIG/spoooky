/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spooooky_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:05:51 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/31 13:28:14 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/spooooky.h"

int main(int argc, char *argv[])
{
	t_params	params;

	if (argc != 2 || !ft_arg_is_valid(argv[1], &params))
	{
		ft_putstr("\033[0;33mAlgun zombie se ha despistado\033[0;37m\n");
		return (0);
	}
	ft_init_grid(&params);
	if (!ft_resolve(params.grid, &params))
	{
		ft_putstr("\033[0;32mHumas wins\033[0;37m\n");
		return (0);
	}
	ft_print_grid(params.grid, params);
	return (1);
}

int	ft_print_grid(char grid[SIZE][SIZE], t_params params)
{
	int	y;
	int	x;

	printf("\033[0;31mHumans lose\033[0;37m\n");
	ft_print_line(params.up);
	y = 0;
	while (y < SIZE)
	{
		x = -1;
		printf("\033[0;35m%d \033[0;37m", params.left[y]);
		while (++x < SIZE)
		{
			printf("%c",grid[y][x]);
			if (x != (SIZE - 1))
				printf(" ");
		}
		printf("\033[0;35m %d\033[0;37m\n", params.right[y]);
		y++;
	}
	ft_print_line(params.down);
	return (1);
}

void	ft_print_line(char	*str)
{
	int	i;
	
	i = 0;
	printf("  ");
	while (i < SIZE)
	{
		printf("\033[0;35m%d \033[0;37m",str[i]);
		i++;
	}
	printf("\n");
}
