#include "move_image.h"


int main(void)
{
	t_mlx	*mlx;
	vec3		pos_a;
	vec3		pos_b;

	pos_a[X] = 20;
	pos_a[Y] = 10;
	pos_b[X] = 60;
	pos_b[Y] = 10;

	pos_a[2] = 0xffffff;
	pos_b[2] = 0xff0000;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)	return (0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDHT, WIN_HEIGHT, "IMAGE MOVE");
	mlx->image =malloc(sizeof(t_image));
	mlx->image->img = mlx_new_image(mlx->mlx, WIN_WIDHT, WIN_HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img,\
										 &(mlx->image->bpp), \
										 &(mlx->image->line_length), \
										 &(mlx->image->endian));
	
	mlx->map = malloc(sizeof(t_map));
	mlx->map->width = 4;
	mlx->map->height = 3;
	mlx->map->pos = malloc(sizeof(vec3 *) * mlx->map->height);
	int i;
	i = 0;
	while (i < mlx->map->height)
	{
		mlx->map->pos[i] = malloc(sizeof(vec3) * mlx->map->width);
		i++;
	}
	terminate(mlx);
	/*
	i = 0;
	int j;
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			mlx->map->pos[i][j][X] = j * j ;
			mlx->map->pos[i][j][Y] = i * i * j;
			mlx->map->pos[i][j][2] = 0xff0000;
			j++;
		}
		i++;
	}
	mlx->map->offset_scaler[X] = 60;
	mlx->map->offset_scaler[Y] = 60;
	mlx->map->offset_scaler[2] = 20;
	printf("init_map\n");
	i = 0;
	while (i <mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			printf("(%3.2f, %3.2f | %#6x)\n", mlx->map->pos[i][j][X], mlx->map->pos[i][j][Y], (unsigned int)mlx->map->pos[i][j][2]);
			j++;
		}
		i++;
	}
	my_mlx_print_map(mlx->image, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->img, 0, 0);
	printf("<mlx> : %p\n", mlx);
	mlx_hook(mlx->win, 2, 1L<<0, keydown, mlx);
	mlx_hook(mlx->win, 3, 1L<<1, keyup, mlx);
	mlx_hook(mlx->win, 4, 1L<<2, mousedown, mlx);
	mlx_hook(mlx->win, 5, 1L<<3, mouseup, mlx);
	mlx_hook(mlx->win, 6, 1L<<6, mousemove, mlx);
	mlx_hook(mlx->win, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx);
	i = 0;
	while (i < mlx->map->height)
	{
		free(mlx->map->pos[i]);
		i++;
	}
	free(mlx->map->pos);
	free(mlx->map);
	free(mlx);
	return (0);
	*/
}