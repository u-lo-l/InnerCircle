/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:11:12 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/28 20:23:44 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/mlx_part.h"
#include "../LIBFT/libft.h"
#include <stdio.h>
#include <math.h>

static double above_cylinder_inside(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	t_vec3	center;
	t_vec3	intersection;
	double	dist;

	center = vec3_add(obj->org, vec3_scale(obj->normal, obj->height));
	dist = vec3_dot(center, obj->normal) / vec3_dot(ray, obj->normal);
	if (dist <= 0)
		return (NAN);
	intersection = vec3_scale(ray, dist);
	if (vec3_l2norm(vec3_subtract(intersection, center)) > obj->radius)
		return (NAN);
	*pcolor = obj->color;
	return (vec3_l2norm(intersection));
}

static double below_cylinder_inside(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	t_vec3	center;
	t_vec3	intersection;
	double	dist;

	center = obj->org;
	dist = vec3_dot(center, obj->normal) / vec3_dot(ray, obj->normal);
	if (dist <= 0)
		return (NAN);
	intersection = vec3_scale(ray, dist);
	if (vec3_l2norm(vec3_subtract(intersection, center)) > obj->radius)
		return (NAN);
	*pcolor = obj->color;
	return (vec3_l2norm(intersection));
}

static double	solve_nearest_intersect_distance(t_vec3 ray, t_vec3 org, double radius)
{
	double	dist;
	double	discriminant;

	discriminant = pow(vec3_l2norm(org), 2) - pow(radius, 2);
	discriminant = discriminant * (pow(vec3_l2norm(ray), 2));
	discriminant = (pow(vec3_dot(ray, org), 2)) - discriminant;
	if (discriminant < 0)
		dist = -1;
	else if (discriminant == 0)
		dist = vec3_dot(ray, org) / pow(vec3_l2norm(ray), 2);
	else
	{
		dist = (vec3_dot(ray, org)) - sqrt(discriminant) / pow(vec3_l2norm(ray), 2);
		if (dist <= 0)
			dist = (vec3_dot(ray, org)) + sqrt(discriminant) / pow(vec3_l2norm(ray), 2);
	}
	if (dist <= 0)
		return (NAN);
	return (dist);
}

static double	outside_cylinder(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	distance;
	double	height;
	t_vec3	intersection;
	t_vec3	ray_proj;
	t_vec3	org_proj;

	ray_proj = vec3_normalize(vec3_cross(obj->normal, vec3_cross(ray, obj->normal)));
	org_proj = vec3_cross(obj->normal, vec3_cross(obj->org, obj->normal));
	distance = solve_nearest_intersect_distance(ray_proj, org_proj, obj->radius);
	if (distance == NAN)
		return (NAN);
	distance /= vec3_dot(ray, ray_proj);
	intersection = vec3_scale(ray, distance);
	height = vec3_dot(vec3_subtract(intersection, obj->org), obj->normal); 
	if (height > obj->height && vec3_dot(obj->normal, ray) < 0)
		return (above_cylinder_inside(ray, obj, pcolor));
	else if (height < 0 && vec3_dot(obj->normal, ray) > 0)
		return (below_cylinder_inside(ray, obj, pcolor));
	else if (height < 0 || height > obj->height)
		return (NAN);
	*pcolor = obj->color;
	return (vec3_l2norm(intersection));
}

double	intersect_cylinder(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	t_vec3	cam_from_cy;
	t_vec3	cam_from_cy_projection;
	double	dist;
	double	height;

	cam_from_cy = vec3_subtract(ray, obj->org);
	cam_from_cy_projection = vec3_cross(obj->normal, vec3_cross(cam_from_cy, obj->normal));
	dist = vec3_l2norm(cam_from_cy_projection);
	if (dist == obj->radius)
		return (NAN);
	else if (dist < obj->radius)
	{
		height = vec3_dot(cam_from_cy, obj->normal);
		if (height == 0 || height == obj->height)
			return (NAN);
		else if (height < 0)
			return (below_cylinder_inside(ray, obj, pcolor));
		else if (height > obj->height)
			return (above_cylinder_inside(ray, obj, pcolor));
	}
	return (outside_cylinder(ray, obj, pcolor));
}
