/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spooooky_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:00:53 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/31 13:27:53 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/spooooky.h"

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

size_t	ft_strlen(char *str)
{
	size_t  i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
