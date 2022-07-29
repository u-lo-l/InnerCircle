/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:47:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/29 19:50:16 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/mlx_part.h"
#include "../LIBFT/libft.h"
#include <math.h>

// discriminant : 이차방정식의 판별식
static double	solve_quadratic_equation(double a, double b, double c)
{
	double solution;
	double discriminant;
	
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		solution = -1;
	else if (discriminant == 0)
		solution = -b;
	else
	{
		solution = -b - sqrt(discriminant);
		if (solution <= 0)
			solution = -b + sqrt(discriminant);
	} 
	if (solution <= 0)
		return (NAN);
	return (solution / (2 * a));
}

static double	intersect_plane(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	dist;
	t_vec3	intersection;
	
	if (vec3_dot(ray, obj->normal) == 0)
		return (NAN);
	dist = vec3_dot(obj->org, obj->normal) / vec3_dot(ray, obj->normal);
	if (dist <= 0)
		return (NAN);
	intersection = vec3_scale(ray, dist);
	*pcolor = obj->color;
	return (dist);
}

static double	intersect_sphere(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	distance;
	t_vec3	intersection;

	distance = solve_quadratic_equation(vec3_dot(ray, ray), \
					-2 * vec3_dot(obj->org, ray), \
					vec3_dot(obj->org, obj->org) - pow(obj->radius, 2));
	if (distance == NAN)
		return (NAN);
	intersection = vec3_scale(ray, distance);
	*pcolor = obj->color;
	return (distance);
}

double object_intersect(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	if (obj->obj_type == E_PLANE)
		return (intersect_plane(ray, obj, pcolor));
	else if (obj->obj_type == E_SPHERE)
		return (intersect_sphere(ray, obj, pcolor));
	else if (obj->obj_type == E_CYLINDER)
		return (intersect_cylinder(ray, obj, pcolor));
	else
		return (NAN);
}
