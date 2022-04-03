#ifndef MOVEIMG
# define MOVEIMG

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#define X 0
#define Y 1
#define WIN_WIDHT 800
#define WIN_HEIGHT 450
typedef double	window_pos[2];
typedef double	vec3[3];

typedef	struct s_map
{
	int		width;
	int 	height;
	vec3	offset_scaler;
	vec3	**pos;
}			t_map;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_image	*image;
	t_map	*map;
	int		onclick;
	int		curr_x;
	int		curr_y;
	int		last_x;
	int		last_y;
}	t_mlx;

int	keydown(int keycode, t_mlx *mlx);
int	keyup(int keycode, t_mlx *mlx);
int	mousedown(int button, int x, int y, t_mlx *mlx);
int	mouseup(int button, int x, int y, t_mlx *mlx);
int	mousemove(int x, int y, t_mlx *mlx);
int	destroy(t_mlx *mlx);
void	terminate(t_mlx *mlx);

int		get_offset(t_image *image, int x, int y);
void	my_mlx_pixel_put(t_image *image, int x, int y, unsigned int color);
void	my_mlx_draw_line(t_image *image, vec3 A, vec3 B, vec3 offset_scaler);
void	my_mlx_print_map(t_image *image, t_map *map);
#endif