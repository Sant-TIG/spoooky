/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spooooky_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:08:32 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/31 13:27:46 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/spooooky.h"

int	ft_arg_is_valid(char *argv, t_params *params)
{
	size_t	i;
	char	*ptr_params;

	i = 0;
	ptr_params = &params->up[0];
	while (argv[i] != '\0')
	{
		if (i % 2 != 0 && argv[i] == ' ')
		{
			i++;
			continue ;
		}
		if (i % 2 != 0 && argv[i] != ' ')
			return (0);
		if (i % 2 == 0 && (argv[i] < '1' || argv[i] > (SIZE + '0')))
			return (0);
		*ptr_params = argv[i] - '0';
		ptr_params++;
		i++;
	}
	return (ft_check_params(i));
}

int ft_check_params(size_t i)
{
	int total;

	total = ((SIZE * SIZE) * 2)  - 1;
	return (i == (size_t) total);
}
