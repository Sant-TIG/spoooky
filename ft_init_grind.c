#include <unistd.h>
#include "spooky.h"

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