/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:47:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/28 05:52:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/mlx_part.h"
#include "../LIBFT/libft.h"
#include <stdio.h>
#include <math.h>
// C    8.660254038,8.660254038,8.660254038  -0.577350269,-0.577350269,-0.577350269  70
// C 0,0,0 -0.707106781,-0.707106781,0 70

static double	solve_nearest_intersect_distance_or_nan(t_vec3 ray, t_vec3 org, double radius)
{
	double	t[2];
	double	discriminant;

	discriminant = pow(vec3_l2norm(org), 2) - pow(radius, 2);
	discriminant = discriminant * (pow(vec3_l2norm(ray), 2));
	discriminant = (pow(vec3_dot(ray, org), 2)) - discriminant;
	if (discriminant < 0)
		t[0] = -1;
	else if (discriminant == 0)
		t[0] = vec3_dot(ray, org) / pow(vec3_l2norm(ray), 2);
	else
	{
		t[0] = (vec3_dot(ray, org)) - sqrt(discriminant) / pow(vec3_l2norm(ray), 2);
		t[1] = (vec3_dot(ray, org)) + sqrt(discriminant) / pow(vec3_l2norm(ray), 2);
		if (t[0] < 0)
			t[0] = t[1];
	}
	if (t[0] <= 0)
		return (NAN);
	return (t[0]);
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

// discriminant : 이차방정식의 판별식
static double	intersect_sphere(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	distance;
	t_vec3	intersection;

	distance = solve_nearest_intersect_distance_or_nan(ray, obj->org, obj->radius);
	if (distance == NAN)
		return (NAN);
	intersection = vec3_scale(ray, distance);
	distance = vec3_l2norm(intersection);
	*pcolor = obj->color;
	return (distance);
}

//!norm 무시하고 우선 작동되는 코드만 작성
//step1 :
//	원기둥을 가상의 평면에 사영시켜 생긴 원과 직선의 교점(Ip) 구하기
//step2 :
//	가상의 평면에 사영된 교점의 실제 위치 구하기
//step3 :
//	원기둥의 높이 범위에 점이 존재하는지 확인하기
//step4 :
//	원기둥의 범위 밖에 교점이 존재한다면, 윗면 혹은 밑면에 존재할 수 있는지 확인한다.
//ERROR!!
//	카메라가 무한원기둥 내부에 존재하면 윗면 밑면을 볼 수 없다.
static double	intersect_cylinder(t_vec3 ray, t_object_base * obj, unsigned int * pcolor)
{
	double	distance;
	t_vec3	intersection;

	//step1 : 사영된 교점 구하기
	t_vec3	ray_proj;
	t_vec3	org_proj;

	ray_proj = vec3_scale(obj->normal, vec3_dot(ray, obj->normal));
	ray_proj = vec3_normalize(vec3_subtract(ray, ray_proj));
	org_proj = vec3_scale(obj->normal, vec3_dot(obj->org, obj->normal));
	org_proj = vec3_subtract(obj->org, org_proj);

	distance = solve_nearest_intersect_distance_or_nan(ray_proj, org_proj, obj->radius);
	if (distance == NAN)
		return (NAN);
	intersection = vec3_scale(ray_proj, distance);
	distance = vec3_l2norm(intersection);

	//step2 : 실제 교점 구하기
	double beta;
	
	beta = acos(vec3_dot(ray, ray_proj));
	if (vec3_dot(obj->normal, ray) < 0)
		beta = -beta;
	intersection = vec3_add(intersection, vec3_scale(obj->normal, distance * tan(beta)));

	//step3 : 높이 확인
	t_vec3	ray_normal_projection;
	double	height;

	ray_normal_projection = vec3_scale(obj->normal, vec3_dot(vec3_subtract(intersection, obj->org), obj->normal));
	height = vec3_l2norm(ray_normal_projection);
	if (vec3_dot(ray_normal_projection, obj->normal) < 0)
		height = -height;
	if (height >= 0 && height <= obj->height)
	{
	// printf("on the side\n");
		*pcolor = obj->color;
	// printf("curr dist : %f, curr color : %x\n", distance, *pcolor);
		return (distance);
	}

	// step4 : 윗 밑면 확인
	t_vec3 target_center;
	double heigt_diff;
	double angle;

	if (height > obj->height && vec3_dot(obj->normal, ray) < 0)
	{
	// printf("on the top\n");
		angle = acos(vec3_dot(obj->normal, ray));
		heigt_diff = obj->height - height;
		target_center = vec3_add(obj->org, vec3_scale(obj->normal, obj->height));
	}
	else if (height < 0 && vec3_dot(obj->normal, ray) > 0)
	{
	// printf("on the bot\n");
		angle = acos(vec3_dot(obj->normal, ray));
		heigt_diff = -height;
		target_center = obj->org;
	}
	else
		return (NAN);
	
	intersection = vec3_add(intersection, vec3_scale(obj->normal, heigt_diff));
	intersection = vec3_add(intersection, vec3_scale(ray_proj, heigt_diff * tan(angle)));
	distance = vec3_l2norm(intersection);
	if (vec3_l2norm(vec3_subtract(target_center, intersection)) > obj->radius)
		return (NAN);
	*pcolor = (obj->color & 0xff0000) / 2  + (obj->color & 0xff00) / 2 + (obj->color & 0xff) / 2;
	
// printf("curr dist : %f, curr color : %x\n", distance, *pcolor);
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
