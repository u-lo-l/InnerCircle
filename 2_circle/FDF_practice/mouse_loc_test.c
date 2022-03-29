
#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>
// #include	"mlx_linux/mlx_int.h"

#define	WIN1_SX		242
#define	WIN1_SY		242
#define	IM1_SX		42
#define	IM1_SY		42
#define	IM3_SX		242
#define	IM3_SY		242

void	*mlx;
void	*win;


typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

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

int	destroy(t_vars *vars)
{
	if (!vars) return (0);
	printf("destroy\n");
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	exit(0);
}

int	mouse_win3(int x,int y, void *p)
{
	printf("Mouse moving in Win3, at %dx%d.\n",x,y);
	return (0);
}

int	main()
{
	t_vars *vars;
	vars = malloc(sizeof(t_vars));
	printf("dd\n");
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 450, "Hello world!");

	mlx_key_hook(vars->win ,keydown, vars);
	mlx_hook(vars->win, 6, 1L<<6, mouse_win3, 0);
	mlx_hook(vars->win, 17, 0 , destroy, vars);

	printf("OK\nNow in Loop. Just play.\n");
	mlx_loop(vars->mlx);
}