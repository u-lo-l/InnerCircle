/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_part.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:29:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/31 23:40:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../INC/scene.h"

#define BACKGROUND (0X222222)



t_mlx	*create_mlx(t_scene *scene, unsigned int width, unsigned int height, char * const filename );

void	delete_mlx(t_mlx *mlx);

void	ft_mlx_set_pixel_color(t_image *img, unsigned int x, \
							unsigned int y, unsigned int color);

void	ft_mlx_set_image_background(t_mlx *mlx);

void	mlx_part(t_scene *scene, unsigned int width, unsigned int height);

/*===MLX EVENT====*/
int		destroy(t_mlx *mlx);
int		keydown(int keycode, t_mlx *mlx);
int		mousedown(int button, int x, int y, t_mlx *mlx);
