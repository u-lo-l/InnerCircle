/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_part.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:29:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/26 14:02:13 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../INC/scene.h"

#define BACKGROUND (0X222222)

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}			t_image;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	unsigned int	width;
	unsigned int	height;
	t_image			*image;
	t_scene			*scene;
}					t_mlx;


t_mlx	*create_mlx(t_scene *scene, unsigned int width, unsigned int height );

void	delete_mlx(t_mlx *mlx);

void	ft_mlx_set_pixel_color(t_image *img, unsigned int x, \
							unsigned int y, unsigned int color);

void	mlx_part(t_scene *scene, unsigned int width, unsigned int height);

/*===MLX EVENT====*/
int		destroy(t_mlx *mlx);
int		keydown(int keycode, t_mlx *mlx);
