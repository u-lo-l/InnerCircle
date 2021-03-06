/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:11:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/31 22:58:06 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/scene.h"
#include "../../LIBFT/libft.h"
#include <stdio.h>
#include <math.h>

void	info_light(t_light *light)
{
	printf("[LIGHT]\n");
	printf("\tpos : [%3.4f, %3.4f, %3.4f]\n", light->org.x \
											, light->org.y \
											, light->org.z);
	printf("\tbrightness : %3.4f\n", light->bright);
	if (light->next)
		info_light(light->next);
}

void	info_camera(t_cam *cam)
{
	printf("[CAMERA]\n");
	printf("\tpos : [%3.4f, %3.4f, %3.4f]\n", cam->pos.x \
											, cam->pos.y \
											, cam->pos.z);
	printf("\tdir : [%3.4f, %3.4f, %3.4f]\n", cam->dir.x \
											, cam->dir.y \
											, cam->dir.z);
	printf("\tHFOV : %3.4f(rad)\n", cam->hfov);
	printf("\tHFOV : %3.4f(deg)\n", (cam->hfov) * (180 / M_PI));
}

void	info_scene(t_scene *scene)
{
	int	red;
	int	green;
	int	blue;

	red = (scene->ambient_color >> 16) & 0xff;
	green = (scene->ambient_color >> 8) & 0xff;
	blue = (scene->ambient_color) & 0xff;
	info_light(scene->light);
	printf("[AMBIENT]\n");
	printf("\tratio : %3.4f\n", scene->ambient_ratio);
	printf("\t\033[38;2;%d;%d;%dmcolor\033[0m", red, green, blue);
	printf(" : r: %d g: %d b: %d\n", red, green, blue);
	info_camera(scene->cam);
	printf("[OBJECTS]\n");
	info_object(scene->obj);
}
