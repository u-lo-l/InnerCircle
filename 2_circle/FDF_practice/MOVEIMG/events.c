#include "move_image.h"

void	terminate(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->height)
	{
		free(mlx->map->pos[i]);
		i++;
	}
	free(mlx->map->pos);
	free(mlx->map);
	free(mlx->image);
	free(mlx);
	exit(0);
}

void	show_mlx_info(t_mlx *mlx)
{
	printf("mlx %p\n",mlx->mlx);
	printf("win %p\n",mlx->win);
	printf("onclick :%d\n",mlx->onclick);
	printf("last x :%d\n",mlx->last_x);
	printf("last y : %d\n",mlx->last_y);
	printf("curr x : %d\n",mlx->curr_x);
	printf("curr y : %d\n",mlx->curr_y);
	printf("img : %p\n", mlx->image);
}

int	keydown(int keycode, t_mlx *mlx)
{
	if (!mlx) return (0);
	printf("key down : %d : ", keycode);
	printf("\n");
	if (keycode == 'Q' || keycode == 'q')
		terminate(mlx);
	if (keycode == 65363)
		mlx->map->offset_scaler[X]++;
	if (keycode == 65361)
		mlx->map->offset_scaler[X]--;
	if (keycode == 65362)
		mlx->map->offset_scaler[Y]--;
	if (keycode == 65364)
		mlx->map->offset_scaler[Y]++;
	// printf("x%f y%f\n", mlx->map->offset_scaler[X], mlx->map->offset_scaler[Y]);
	return (1);
}

int	keyup(int keycode, t_mlx *mlx)
{
	if (!mlx) return (0);
	printf("key up %d : ", keycode);
	printf("\n");
	if (keycode == 'Q' || keycode == 'q')
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(0);
		return (0);
	}
	mlx_destroy_image(mlx->mlx, mlx->image->img);
	printf("A\n");
	mlx->image =malloc(sizeof(t_image));
	mlx->image->img = mlx_new_image(mlx->mlx, WIN_WIDHT, WIN_HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img,\
										 &(mlx->image->bpp), \
										 &(mlx->image->line_length), \
										 &(mlx->image->endian));
	my_mlx_print_map(mlx->image, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->img, 0, 0);
	return (1);
}

int	mousedown(int button, int x, int y, t_mlx *mlx)
{
	printf("mouse_down : %d\n", button);
	show_mlx_info(mlx);
	mlx->onclick = 1;
	printf("AA\n");
	mlx_clear_window(mlx->mlx, mlx->win);
	return (0);
}

int	mouseup(int button, int x, int y, t_mlx *mlx)
{
	printf("mouse_up : %d\n", button);
	mlx->onclick = 0;
	return (0);
}

int	mousemove(int x, int y, t_mlx *mlx)
{
	printf("mouse_move : (%03d, %03d)\n", x, y);
	if (mlx->onclick == 1)
	{
		printf("!\n");
	}
	return (0);
}

int	expose(t_mlx *mlx)
{
	printf("expose\n");
	return (0);
}

int	destroy(t_mlx *mlx)
{
	if (!mlx) return (0);
	printf("destroy\n");
	terminate(mlx);
}