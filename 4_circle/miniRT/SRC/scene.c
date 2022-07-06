/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:49:19 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 09:31:42 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/scene.h"
#include <stdlib.h>

t_scene	*create_empty_scene( void )
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (scene == NULL)
		return (NULL);
	scene->light_org = NULL;
	scene->cam_org = NULL;
	scene->cam_dir = NULL;
	scene->light_brightness = 0;
	scene->ambient_ratio = 0;
	scene->ambient_color = 0;
	scene->first = NULL;
	return (scene);
}

void free_scene(t_scene **pscene)
{
	free_vec3((*pscene)->light_org);
	free_vec3((*pscene)->cam_org);
	free_vec3((*pscene)->cam_dir);
	// free objects;
	free(*pscene);
	*pscene = NULL;
}

int	set_light(t_scene *scene, t_vec3 *org, double b)
{
	if (!org || b < 0.0 || b > 1.0)
		return (0);
	scene->light_org = org;
	scene->light_brightness = b;
}

int	set_ambient(t_scene *scene, double r, int c)
{
	if (c < 0 || c > 256)
		return (0);
	if (r < 0.0 || r > 1.0)
		return (0);
	scene->ambient_color = c;
	scene->ambient_ratio = r;
}

int set_cam(t_scene *scene, t_vec3 *pos, t_vec3 *dir)
{
	if (!pos || !dir)
		return (0);
	scene->cam_org = pos;
	scene->cam_org = dir;
	return (1);
}

#include <stdio.h>
int main()
{
	t_scene	scene;

	printf("%d\n", scene.ambient_color);
}