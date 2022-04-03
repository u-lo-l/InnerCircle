#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct		s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}					t_cam;

typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	t_mouse		*mouse;
	double		**zbuf;
}					t_mlx;

t_mlx		*init(char *title)
{
	t_mlx	*mlx;

	if ((mlx = malloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->win = mlx_new_window(mlx->mlx, 1600,
			900, title)) == NULL ||
		(mlx->mouse = malloc(sizeof(t_mouse))) == NULL)
	{
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->lastx = mlx->mouse->x;
	mlx->mouse->lasty = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown & (1 << 1) && mlx->mouse->isdown & (1 << 2))
	{
		printf("case1\n");
		printf("last : (%3d, %3d) ",mlx->mouse->lastx, mlx->mouse->lasty);
		printf("curr : (%3d, %3d)\n", x, y);
		// printf("(x - mlx->mouse->lastx) : %d\n", (x - mlx->mouse->lastx));
		// printf("(y - mlx->mouse->lasty) : %d\n", (y - mlx->mouse->lasty));
	}
	else if (mlx->mouse->isdown & (1 << 1))
	{
		printf("case2\n");
		printf("last : (%3d, %3d) ",mlx->mouse->lastx, mlx->mouse->lasty);
		printf("curr : (%3d, %3d)\n", x, y);
		// mlx->cam->x += (mlx->mouse->lasty - y) / 200.0f;
		// mlx->cam->y -= (mlx->mouse->lastx - x) / 200.0f;
	}
	else if (mlx->mouse->isdown & (1 << 2))
	{
		printf("case3\n");
		printf("last : (%3d, %3d) ",mlx->mouse->lastx, mlx->mouse->lasty);
		printf("curr : (%3d, %3d)\n", x, y);
		// mlx->cam->scale += (mlx->mouse->lasty - y) / 10.0f + 0.5f;
		// if (mlx->cam->scale < 1)
		// 	mlx->cam->scale = 1;
	}
	if (mlx->mouse->isdown)
		// render(mlx);
	return (0);
}

int	destroy(t_mlx *vars)
{
	if (!vars) return (0);
	printf("destroy\n");
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	mlx = init("HI");

	mlx_hook(mlx->win, 4, 1<<2, hook_mousedown, mlx);
	mlx_hook(mlx->win, 5, 1<<3, hook_mouseup, mlx);
	mlx_hook(mlx->win, 6, 1<<6, hook_mousemove, mlx);
	mlx_hook(mlx->win, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}