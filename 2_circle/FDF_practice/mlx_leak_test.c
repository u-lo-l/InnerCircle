#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
}					t_mlx;

int	destroy(t_mlx *mlx)
{
	// if (!mlx) return (0);
	mlx_loop_end(mlx->mlx);
	printf("destroy\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	printf("destroy\n");
	mlx_destroy_display(mlx->mlx);
	printf("destroy\n");
	free(mlx->mlx);
	printf("destroy\n");
	free(mlx);
	printf("destroy\n");
	exit(0);
	return (1);
}

int	main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1660, 900, "Hello world!");
	mlx_hook(mlx->win, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx);
}