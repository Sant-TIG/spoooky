/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spooooky_inits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:21:17 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/31 12:35:56 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/spooooky.h"

void	ft_init_grid(t_params *params)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			params->grid[i][j] = 0;
	}
}