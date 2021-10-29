#ifndef SPOOKY_H

# define	SPOOKY_H
# define    SIZE 4

typedef struct s_params
{
	char	up[SIZE];
	char	down[SIZE];
	char	left[SIZE];
	char	right[SIZE];
	char	grid[SIZE][SIZE];
}	t_params;

int     spooooky_zombie(void);
size_t  ft_strlen(char *str);
int     ft_putstr(char *str);
int     ft_check_params(size_t i);
int	    arg_is_valid(char *av, t_params *params);
int	    resolve(char grid[SIZE][SIZE], t_params *params);
int	    search_empty_case(char grid[SIZE][SIZE], int *x, int *y);
int	    can_put_value(char grid[SIZE][SIZE], int x, int y, int value);
int	    line_is_valid(char grid[SIZE][SIZE], t_params *params, int y);
int	    column_is_valid(char grid[SIZE][SIZE], t_params *params, int x);
int	    calculate_views(char grid[SIZE][SIZE], int pos);
int	    print_grid(char grid[SIZE][SIZE]);
void	ft_init_grid(t_params *params);

#endif