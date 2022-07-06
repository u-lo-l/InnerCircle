/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:06:19 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 08:08:02 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <stdlib.h>
#include <math.h>

t_vec3	*vec3_subtract(t_vec3 *a, t_vec3 *b)
{
	return (create_vec3(a->x - b->x, a->y - b->y, a->z - b->z));
}

t_vec3	*vec3_scale(t_vec3 *a, double s)
{
	if (!a)
		return (NULL);
	a->x *= s;
	a->y *= s;
	a->z *= s;
	return (a);
}

double	vec3_dot(t_vec3	*a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec3	*vec3_cross(t_vec3 *a, t_vec3 *b)
{
	double	x;
	double	y;
	double	z;

	x = a->y * b->z - a->z * b->y;
	y = a->z * b->x - a->x * b->z;
	z = a->x * b->y - a->y * b->x;
	return (create_vec3(x, y, z));
}
