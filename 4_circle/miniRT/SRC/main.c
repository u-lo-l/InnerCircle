/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:25:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/08/01 01:10:37 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/scene.h"
#include "../LIBFT/libft.h"
#include "../INC/mlx_part.h"
#include "COLOR/color.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_scene	*global_scene;
	
	if (argc != 2 || argv == NULL)
	{
		printf("ERR : usage : ./miniRT <FILENAME>\n");
		return (1);
	}
	printf("\033[1;33m==============MINI_RT==============\033[0m\n");
	global_scene = create_empty_scene();
	if (init_scene(global_scene, argv[1]) == FALSE)
	{
		printf("\033[3;31mFail to read file\033[0m\n");
		free_scene(global_scene);
		return (1);
	}
	printf("GLOBAL COORDINATE\n");
	info_scene(global_scene);
	transform_to_cam_cord(global_scene);
	printf("CAMERA COORDINATE\n");
	info_scene(global_scene);
	
	{
		t_mlx	*mlx;
		mlx = create_mlx(global_scene, 960, 540, argv[1]);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->img, 0, 0);
		mlx_destroy_image(mlx->mlx, mlx->image->img);
		mlx->image->img = mlx_new_image(mlx->mlx, 960, 540);
		mlx->image->addr = mlx_get_data_addr(mlx->image->img, &(mlx->image->bpp), \
									&(mlx->image->line), &(mlx->image->endian));
		ray_cast(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->img, 0, 0);
		mlx_hook(mlx->win, 17, 0, destroy, mlx);
		mlx_hook(mlx->win, 2, 0, keydown, mlx);
		mlx_hook(mlx->win, 4, 0, mousedown, mlx);
		mlx_loop(mlx->mlx);
	}
	free_scene(global_scene);

	// system("leaks miniRT");
}

