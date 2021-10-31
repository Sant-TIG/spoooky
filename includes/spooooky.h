/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spooooky.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:35:24 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/31 13:11:29 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOOOOKY_H
# define SPOOOOKY_H

# define	SIZE 4

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

typedef struct s_params
{
	int		i;
	char	grid[SIZE][SIZE];
	char	up[SIZE];
	char	down[SIZE];
	char	left[SIZE];
	char	right[SIZE];
}	t_params;

//	UTILITIES
int		ft_putstr(char *str);
size_t	ft_strlen(char *str);

//	CHECK
int	ft_arg_is_valid(char *argv, t_params *params);
int	ft_check_params(size_t i);

//INIT
void	ft_init_grid(t_params *params);

//	RESOLVE
int	ft_resolve(char grid[SIZE][SIZE], t_params *params);
int	ft_search_empty_case(char grid[SIZE][SIZE], int *x, int *y);
int	ft_can_put_value(char grid[SIZE][SIZE], int x, int y, int value);
int	ft_column_is_valid(char grid[SIZE][SIZE], t_params *params, int x);
int	ft_line_is_valid(char grid[SIZE][SIZE], t_params *params, int y);

//PRINT
int	ft_print_grid(char grid[SIZE][SIZE], t_params params);
void	ft_print_line(char	*str);

#endif
