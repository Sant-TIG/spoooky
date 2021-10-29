#include <unistd.h>
#include "spooky.h"
#include <stdio.h>

int	print_grid(char grid[SIZE][SIZE])
{
	int	y;
	int	x;

	y = 0;
	while (y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
		{
			write(1, &grid[y][x], 1);
			if (x != (SIZE - 1))
				write(1, " ", 1);
		}
		write (1, "\n", 1);
		y++;
	}
	return (1);
}

int 	resolve(char grid[SIZE][SIZE], t_params *params)
{
	int	x;
	int	y;
	int	value;

	if (search_empty_case (grid, &x, &y))
	{
		value = '0';
		while (++value <= (SIZE + '0'))
		{
			if (can_put_value (grid, x, y, value))
			{
				grid[y][x] = value;
				if (x == (SIZE - 1) && !line_is_valid (grid, params, y))
					continue ;
				if (y == (SIZE - 1) && !column_is_valid(grid, params, x))
					continue ;
				if (resolve(grid, params) == 1)
					return (1);
			}
		}
		grid[y][x] = 0;
		return (0);
	}
	return (1);
}

int	arg_is_valid(char *argv, t_params *params)
{
	size_t	i;
	char	*ptr_params;

	i = 0;
	ptr_params = &params -> up[0];
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
    return(ft_check_params(i));
}

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc != 2 || !arg_is_valid(argv[1], &params))
	{
		ft_putstr("Algun zombie se ha despistado\n");
        spooooky_zombie();
		return (0);
	}
	ft_init_grid(&params);
	if (!resolve(params.grid, &params))
	{
		ft_putstr("Humnas Wins\n");
		return (0);
	}
	print_grid(params.grid);
	return (1);
}
