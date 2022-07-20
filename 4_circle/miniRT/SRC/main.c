/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:25:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 03:00:30 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/scene.h"
#include "../LIBFT/libft.h"
#include <stdio.h>
// #include "../Libft_vector/vector3.h"
// #include "../Libft_vector/matrix33.h"
// #include "../Libft_vector/quaternion.h"

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
	free_scene(global_scene);
}