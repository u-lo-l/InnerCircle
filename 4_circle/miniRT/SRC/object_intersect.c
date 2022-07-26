/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:47:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/26 16:06:08 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/mlx_part.h"
#include "../LIBFT/libft.h"
#include <stdio.h>
#include <math.h>

static double	intersect_plane(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	t;
	double	dist;
	t_vec3	intersection;
	
	if (vec3_dot(ray, obj->org) == 0)
		return (nan(""));
	t = vec3_dot(obj->org, obj->normal) / vec3_dot(ray, obj->normal);
	intersection = vec3_scale(ray, t);
	printf("plane type. intersection seeking.\n");
	printf("\tpos : [%3.4f, %3.4f, %3.4f]\n", intersection.x \
											, intersection.y \
											, intersection.z);
	dist = vec3_l2norm(intersection);
	*pcolor = obj->color;
	return (dist);
}

static double	intersect_sphere(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	t[2];
	double	discriminant;
	double	dist;
	t_vec3	intersection;

	discriminant = pow(vec3_l2norm(obj->org), 2) - pow(obj->radius, 2);
	discriminant = discriminant * (pow(vec3_l2norm(ray), 2));
	discriminant = (pow(vec3_dot(ray, obj->org), 2)) - discriminant;
	printf("D = %f\n", discriminant);
	if (discriminant < 0)
		t[0] = -1;
	else if (discriminant == 0)
		t[0] = vec3_dot(ray, obj->org) / pow(vec3_l2norm(ray), 2);
	else
	{
		t[0] = (vec3_dot(ray, obj->org)) - sqrt(discriminant) / pow(vec3_l2norm(ray), 2);
		t[1] = (vec3_dot(ray, obj->org)) + sqrt(discriminant) / pow(vec3_l2norm(ray), 2);
		if (t[0] < 0)
			t[0] = t[1];
	}
	if (t[0] < 0)
		return (nan(""));
	intersection = vec3_scale(ray, t[0]);
	dist = vec3_l2norm(intersection);
	*pcolor = obj->color;
	printf("sphere type. intersection seeking.\n");
	printf("\tpos : [%3.4f, %3.4f, %3.4f]\n", intersection.x \
											, intersection.y \
											, intersection.z);
	return (dist);
}

static double	intersect_cylinder(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	t[2];
	double	discriminant;
	double	dist;
	t_vec3	intersection;
	t_vec3	ray_prime;
	t_vec3	org_prime;

	ray_prime = vec3_cross(obj->normal, vec3_cross(ray, obj->normal));
	org_prime = vec3_cross(obj->normal, vec3_cross(obj->org, obj->normal));

	discriminant = pow(vec3_l2norm(org_prime), 2) - pow(obj->radius, 2);
	discriminant = discriminant * (pow(vec3_l2norm(ray_prime), 2));
	discriminant = (pow(vec3_dot(ray_prime, org_prime), 2)) - discriminant;
	printf("D = %f\n", discriminant);
	if (discriminant < 0)
		t[0] = -1;
	else if (discriminant == 0)
		t[0] = vec3_dot(ray_prime, org_prime) / pow(vec3_l2norm(ray_prime), 2);
	else
	{
		t[0] = (vec3_dot(ray_prime, org_prime)) - sqrt(discriminant) / pow(vec3_l2norm(ray_prime), 2);
		t[1] = (vec3_dot(ray_prime, org_prime)) + sqrt(discriminant) / pow(vec3_l2norm(ray_prime), 2);
		if (t[0] < 0)
			t[0] = t[1];
	}
	intersection = vec3_scale(ray_prime, t[0]);
	printf("\tA : [%3.4f, %3.4f, %3.4f]\n", intersection.x \
											, intersection.y \
											, intersection.z);
	printf("\tO : [%3.4f, %3.4f, %3.4f]\n", obj->org.x \
											, obj->org.y \
											, obj->org.z);
	printf("\tOA : [%3.4f, %3.4f, %3.4f]\n", vec3_subtract(intersection, obj->org).x \
											, vec3_subtract(intersection, obj->org).y \
											, vec3_subtract(intersection, obj->org).z);
	double height = vec3_dot(vec3_subtract(intersection, obj->org), obj->normal);
	printf("cylinder type. intersection seeking.\n");
	printf("\tpos : [%3.4f, %3.4f, %3.4f]\n", intersection.x \
											, intersection.y \
											, intersection.z);
	printf("height : %f\n", height);
	if (0 > height || height > obj->height)
	{
		// 윗 면과 아랫 면 원에 대해서 교점 찾는 과정 필요함.
		return (nan(""));
	}
	dist = vec3_l2norm(intersection);
	*pcolor = obj->color;
	printf("cylinder type. intersection seeking.\n");
	printf("\tpos : [%3.4f, %3.4f, %3.4f]\n", intersection.x \
											, intersection.y \
											, intersection.z);
	return (dist);
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
		return (nan(""));
}
