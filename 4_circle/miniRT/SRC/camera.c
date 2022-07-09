/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:11:01 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/09 20:28:00 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/scene.h"
#include "../LIBFT/libft.h"
#include "../Libft_vector/vector3.h"
#include <stdlib.h>

int	case_camera(t_scene *scene, char **single_scene)
{
	if (scene->cam != NULL)
		return (FALSE);
	if (ft_strsetlen(single_scene) != 4)
		return (FALSE);
	scene->cam = malloc(sizeof(t_cam));
	if (!scene->cam)
		return (FALSE);
	if (str_to_vec3(single_scene[1], &(scene->cam->pos)) == FALSE \
		|| str_to_vec3(single_scene[2], &(scene->cam->dir)) == FALSE \
		|| ft_strtod(single_scene[3], &(scene->cam->hfov)) == FALSE)
		return (FALSE);
	if (vec3_l2norm(&(scene->cam->dir)) > 1.001 \
		|| vec3_l2norm(&(scene->cam->dir)) < 0.999)
		return (FALSE);
	return (TRUE);
}
