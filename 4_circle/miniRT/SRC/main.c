/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:25:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/26 15:34:44 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/scene.h"
#include "../LIBFT/libft.h"
#include "../INC/mlx_part.h"
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

	printf("SEEK INTERSECTION\n");
	// mlx_part(global_scene, 1920, 1080);
	t_vec3 ray = create_vec3(0, 0, 1);
	unsigned int color;
	object_intersect(ray, global_scene->obj, &color);
	free_scene(global_scene);
	// system("leaks miniRT");
}

