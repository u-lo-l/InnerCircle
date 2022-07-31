/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:14:36 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/31 23:28:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft_vector/vector3.h"
#include "../../INC/scene.h"

// 카메라가 물체 안에 있는 경우느 고려되지 않았다.
static t_vec3 get_cylinder_normal(t_object_base *obj, t_vec3 intersection);

t_vec3 get_normal_vector(t_object_base *obj, t_vec3 intersection)
{
	if (obj->obj_type == E_PLANE)
		return (obj->normal);
	else if (obj->obj_type == E_SPHERE)
		return (vec3_normalize(vec3_subtract(intersection, obj->org)));
	else if (obj->obj_type == E_CYLINDER)
		return (vec3_normalize(get_cylinder_normal(obj, intersection)));
	return (create_vec3(0, 0, 0));
}

static t_vec3 get_cylinder_normal(t_object_base *O, t_vec3 I)
{
	t_vec3	relative_i;
	double	height;

	relative_i = vec3_subtract(I, O->org);
	height = vec3_dot(relative_i, O->normal);
	if (height == O->height)
		return (O->normal);
	else if (height == 0)
		return (vec3_scale(O->normal, -1));
	else
		return (vec3_cross(O->normal, vec3_cross(relative_i, O->normal)));
}
