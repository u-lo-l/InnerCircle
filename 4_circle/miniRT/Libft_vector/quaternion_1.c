/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 07:32:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 08:05:39 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include <stdlib.h>
#include <math.h>

t_quat	*quat_by_elements(double w, double x, double y, double z)
{
	t_quat	*q;
	t_vec3	*k;

	k = create_vec3(x, y, z);
	if (!k)
		return (NULL);
	q = quat_by_vector(w, k);
	if (!q)
		free(k);
	return (q);
}

t_quat	*quat_by_vector(double w, t_vec3 *k)
{
	t_quat	*q;

	if (!k)
		return (NULL);
	q = malloc(sizeof(t_quat));
	if (!q)
		return (NULL);
	q->w = w;
	q->k = create_vec3(k->x, k->y, k->z);
	return (q);
}

void	free_quaternion(t_quat **pquat)
{
	free(*pquat);
	*pquat = NULL;
}

double	quat_l2norm(t_quat *q)
{
	double	length;

	length = pow(q->w, 2) + pow(vec3_l2norm(q->k), 2);
	length = sqrt(length);
	return (length);
}

t_quat	*quat_normalize(t_quat *q)
{
	double	norm;

	norm = quat_l2norm(q);
	if (norm == 0)
		return (q);
	q->w /= norm;
	q->k->x /= norm;
	q->k->y /= norm;
	q->k->z /= norm;
	return (q);
}
