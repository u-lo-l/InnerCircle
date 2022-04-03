#include "move_image.h"

int main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)	return;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 800, 450, "IMAGE MOVE");
	mlx->image.img = mlx_new_image(mlx->mlx, 800, 450);
	mlx->image->addr = mlx_get_data_addr(mlx->image.img,\
										 &(mlx->image.bpp), \
										 &(mlx->image.line_length), \
										 (mlx->image.endian));
	my_mlx_draw_line(&img, pos_a, pos_b,0xFFFF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx->win, 4, 1<<2, hook_mousedown, mlx);
	mlx_hook(mlx->win, 5, 1<<3, hook_mouseup, mlx);
	mlx_hook(mlx->win, 6, 1<<6, hook_mousemove, mlx);
	mlx_hook(mlx->win, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx);
	free(mlx);
	return (0);
}
