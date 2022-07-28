/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:47:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/28 20:23:05 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/mlx_part.h"
#include "../LIBFT/libft.h"
#include <math.h>

// discriminant : 이차방정식의 판별식
static double	solve_nearest_intersect_distance(t_vec3 ray, t_vec3 org, double radius)
{
	double	t;
	double	discriminant;

	discriminant = pow(vec3_l2norm(org), 2) - pow(radius, 2);
	discriminant = discriminant * (pow(vec3_l2norm(ray), 2));
	discriminant = (pow(vec3_dot(ray, org), 2)) - discriminant;
	if (discriminant < 0)
		t = -1;
	else if (discriminant == 0)
		t = vec3_dot(ray, org) / pow(vec3_l2norm(ray), 2);
	else
	{
		t = (vec3_dot(ray, org)) - sqrt(discriminant) / pow(vec3_l2norm(ray), 2);
		if (t <= 0)
			t = (vec3_dot(ray, org)) + sqrt(discriminant) / pow(vec3_l2norm(ray), 2);
	}
	if (t <= 0)
		return (NAN);
	return (t);
}

static double	intersect_plane(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	t;
	double	dist;
	t_vec3	intersection;
	
	if (vec3_dot(ray, obj->normal) == 0)
		return (NAN);
	t = vec3_dot(obj->org, obj->normal) / vec3_dot(ray, obj->normal);
	if (t <= 0)
		return (NAN);
	intersection = vec3_scale(ray, t);
	dist = vec3_l2norm(intersection);
	*pcolor = obj->color;
	return (dist);
}

static double	intersect_sphere(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	distance;
	t_vec3	intersection;

	distance = solve_nearest_intersect_distance(ray, obj->org, obj->radius);
	if (distance == NAN)
		return (NAN);
	intersection = vec3_scale(ray, distance);
	distance = vec3_l2norm(intersection);
	*pcolor = obj->color;
	return (distance);
}

double object_intersect(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	if (ft_strncmp(obj->type, T_PLANE, ft_strlen(T_PLANE) + 1) == 0)
		return (intersect_plane(ray, obj, pcolor));
	else if (ft_strncmp(obj->type, T_SPHERE, ft_strlen(T_SPHERE) + 1) == 0)
		return (intersect_sphere(ray, obj, pcolor));
	else if (ft_strncmp(obj->type, T_CYLINDER, ft_strlen(T_CYLINDER) + 1) == 0)
		return (intersect_cylinder(ray, obj, pcolor));
	else
		return (NAN);
}
