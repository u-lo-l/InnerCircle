#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	print_int_bits(int n)
{
	int	i;
	char bits[33];

	bits[32] = 0;
	i = 0;
	while (i < 32)
	{
		bits[i] = ((n >> (31 - i)) & 1) + '0';
		i++;
	}
	printf("%s", bits);
}

int	keydown(int keycode, t_vars *vars)
{
	if (!vars) return (0);
	printf("key down : %d : ", keycode);
	print_int_bits(keycode);
	printf("\n");
	if (keycode == 'Q' || keycode == 'q')
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	return (1);
}

int	keyup(int keycode, t_vars *vars)
{
	if (!vars) return (0);
	printf("key up %d : ", keycode);
	print_int_bits(keycode);
	printf("\n");
	if (keycode == 'Q' || keycode == 'q')
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars);
		exit(0);
		return (0);
	}
	return (1);
}

int	mousedown(int button, t_vars *vars)
{
	printf("mouse_down : %d\n", button);
	return (0);
}

int	mouseup(int button, t_vars *vars)
{
	printf("mouse_up : %d\n", button);
	return (0);
}

int	mousemove(int x, int y, void *p)
{
	printf("mouse_move : (%03d, %03d)\n", x, y);
	return (0);
}

int	destroy(t_vars *vars)
{
	if (!vars) return (0);
	printf("destroy\n");
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	exit(0);
}

int	main(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 450, "Hello world!");
	mlx_hook(vars->win, 2, 1L<<0, keydown, vars);
	mlx_hook(vars->win, 3, 1L<<1, keyup, vars);
	mlx_hook(vars->win, 4, 1L<<2, mousedown, NULL);
	mlx_hook(vars->win, 5, 1L<<3, mouseup, NULL);
	mlx_hook(vars->win, 6, 1L<<6, mousemove, NULL);
	mlx_hook(vars->win, 17, 0, destroy, vars);
	mlx_loop(vars->mlx);
}