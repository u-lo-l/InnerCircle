/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 07:05:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 08:07:55 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <stdlib.h>
#include <math.h>

t_vec3	*create_vec3(double x, double y, double z)
{
	t_vec3	*new_vec3;

	if (isnan(x) || isnan(y) || isnan(z) || isinf(x) || isinf(y) || isinf(z))
		return (NULL);
	new_vec3 = malloc(sizeof(t_vec3));
	if (!new_vec3)
		return (NULL);
	new_vec3->x = x;
	new_vec3->y = y;
	new_vec3->z = z;
	return (new_vec3);
}

void	free_vec3(t_vec3 **pvec_3)
{
	free(*pvec_3);
	*pvec_3 = NULL;
}

double	vec3_l2norm(t_vec3 *a)
{
	double	length;

	length = pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2);
	length = sqrt(length);
	return (length);
}

t_vec3	*vec3_normalize(t_vec3 *a)
{
	double	length;

	length = vec3_l2norm(a);
	if (!length)
		return (a);
	a->x /= length;
	a->y /= length;
	a->z /= length;
	return (a);
}

t_vec3	*vec3_add(t_vec3 *a, t_vec3 *b)
{
	return (create_vec3(a->x + b->x, a->y + b->y, a->z + b->z));
}
