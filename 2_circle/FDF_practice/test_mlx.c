#include <mlx.h>
#include <math.h>
#include <stdio.h>
#define X 0
#define Y 1

typedef double	window_pos[2];

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		get_offset(t_data *data, int x, int y)
{
	return (y * data->line_length + x * (data->bits_per_pixel/8));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + get_offset(data, x, y);
	*(int*)dst = color;
}

void	my_mlx_draw_line(t_data *data, window_pos A, window_pos B, int color)
{
	double delta_x;
	double delta_y;
	double denominator;

	delta_x = (B[X] - A[X]);
	delta_y = (B[Y] - A[Y]);
	denominator = fmax(fabs(delta_x), fabs(delta_y));
	delta_x /= denominator;
	delta_y /= denominator;
	while ((int)(A[X] - B[X]) || (int)(A[Y] - B[Y]))
	{
		my_mlx_pixel_put(data, (int)A[X], (int)A[Y], color);
		A[X] += delta_x;
		A[Y] += delta_y;
	}
	my_mlx_pixel_put(data, (int)B[X], (int)B[Y], 0X00FFFFFF);
}


int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	window_pos	pos_a;
	window_pos	pos_b;

	pos_a[X] = 200;
	pos_a[Y] = 100;

	pos_b[X] = 600;
	pos_b[Y] = 100;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 450, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 450);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// my_mlx_pixel_put(&img, 400, 440, 0x00FF0000);
	my_mlx_draw_line(&img, pos_a, pos_b,0xFFFF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}