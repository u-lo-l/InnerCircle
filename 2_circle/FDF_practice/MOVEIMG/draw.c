#include "move_image.h"
#include <math.h>
#include <unistd.h>
int		get_offset(t_image *image, int x, int y)
{
	return (y * image->line_length + x * (image->bpp/8));
}

void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color)
{
	char	*dst;
	if (0 > x || WIN_WIDHT <= x || 0 > y || WIN_HEIGHT <= y)
		return ;
	dst = image->addr + get_offset(image, x, y);
	*(unsigned int*)dst = color;
}

void	my_mlx_draw_line(t_image *image, vec3 A, vec3 B, vec3 offset_scaler)
{
	double	denominator;
	vec3	delta;
	vec3	temp_a;
	vec3	temp_b;

	temp_a[X] = A[X] * offset_scaler[2] + offset_scaler[X];
	temp_a[Y] = A[Y] * offset_scaler[2] + offset_scaler[Y];
	temp_b[X] = B[X] * offset_scaler[2] + offset_scaler[X];
	temp_b[Y] = B[Y] * offset_scaler[2] + offset_scaler[Y];
	delta[X] = (temp_b[X] - temp_a[X]);
	delta[Y] = (temp_b[Y] - temp_a[Y]);
	delta[2] = (B[2] - A[2]);
	denominator = fmax(fabs(delta[X]), fabs(delta[Y]));
	delta[X] /= denominator;
	delta[Y] /= denominator;
	delta[2] /= denominator;
	printf("{(%3.2f, %3.2f) to (%3.2f, %3.2f)}\n", temp_a[X], temp_a[Y],temp_b[X], temp_b[Y]);
	while ((int)(temp_a[X] - temp_b[X]) || (int)(temp_a[Y] - temp_b[Y]))
	{
		my_mlx_pixel_put(image, (int)temp_a[X], (int)temp_a[Y], (unsigned int)A[2]);
		temp_a[X] += delta[X];
		temp_a[Y] += delta[Y];
		A[2] += delta[2];
	}
	my_mlx_pixel_put(image, (int)temp_b[X], (int)temp_b[Y], (unsigned int)B[2]);
}

void	my_mlx_print_map(t_image *image, t_map *map)
{
	int	i;
	int	j;

	if (!image || !map)
		return ;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width - 1)
			my_mlx_draw_line(image, map->pos[i][j], map->pos[i][j + 1], map->offset_scaler);
	}
	i = -1;
	while (++i < map->height - 1)
	{
		j = -1;
		while(++j < map->width)
			my_mlx_draw_line(image, map->pos[i][j], map->pos[i + 1][j], map->offset_scaler);
	}
}