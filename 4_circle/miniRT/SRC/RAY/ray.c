/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:08:24 by dkim2             #+#    #+#             */
/*   Updated: 2022/08/01 01:03:38 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/scene.h"
#include "../../INC/mlx_part.h"
#include "../../Libft_vector/vector3.h"
#include "../COLOR/color.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// t_ray	*create_ray(t_vec3 org, t_vec3 dir)
// {
// 	return (NULL);
// }

// void	free_raylst(t_ray **pray)
// {
// 	t_ray	*curr;
// 	t_ray	*next;

// 	curr = *pray;
// 	while (curr)
// 	{
// 		next = curr->next;
// 		free(curr);
// 		curr = next;
// 	}
// 	free(*pray);
// 	*pray = NULL;
// }

static unsigned int secondary_ray_cast(t_mlx *mlx, t_vec3 intersection, t_object_base *obj, int print)
{
	unsigned int	hex;
	double			diffuse;
	t_color			color;
	t_vec3			normal;
	t_vec3			ray;

	normal = vec3_normalize(get_normal_vector(obj, intersection));
	ray = vec3_normalize(vec3_subtract(mlx->scene->light->org, intersection));
	if (print)
	{
		printf("\n\tintersection : [%f %f %f]", intersection.x, intersection.y, intersection.z);
		printf("\n\tobj->org : [%f %f %f]", obj->org.x, obj->org.y, obj->org.z);
		printf("\n\tnormal : [%f %f %f]", normal.x, normal.y, normal.z);
		printf("\n\tray : [%f %f %f]", ray.x, ray.y, ray.z);
		t_vec3 light = vec3_subtract(mlx->scene->light->org, intersection);
		printf("\n\trelative light : [%f %f %f], ", light.x, light.y, light.z);
	}
	color = hex_color(obj->color);
	intersection = vec3_add(intersection, vec3_scale(normal, 0.01));


	t_object_base	*target_obj;
	double			dist[2];

	dist[0] = INFINITY;
	target_obj = mlx->scene->obj;
	while (target_obj)
	{
		dist[1] = object_intersect(ray, target_obj, &hex, intersection);
		if ((dist[1] != NAN) && (dist[1] < dist[0]))
			dist[0] = dist[1];
		target_obj = target_obj->next;
	}
	
	if (print)
	{
		printf("\n\tdist : %f ", dist[0]);
		printf("\t\033[38;2;%d;%d;%dmoriginal color\033[0m", color.red, color.green, color.blue);
		printf(" : r: %d g: %d b: %d\n", color.red, color.green, color.blue);
	}
	diffuse = vec3_dot(ray, normal) * mlx->scene->light->bright;
	if ((isnan(dist[0]) || dist[0] >  vec3_l2norm(vec3_subtract(mlx->scene->light->org, intersection))) && diffuse > 0)
	{
		color = color_add(color_scale(color, diffuse), color_scale(color, mlx->scene->ambient_ratio));
		if (print)
		{
			printf("diffuse : %f", diffuse);
			printf("\t\033[38;2;%d;%d;%dmcolor\033[0m", color.red, color.green, color.blue);
			printf(" : r: %d g: %d b: %d\n", color.red, color.green, color.blue);
		}
		return (color_to_hex(color));
	}
	color = color_scale(color, mlx->scene->ambient_ratio);
	if (print)
	{
		printf("ambient");
		printf("\t\033[38;2;%d;%d;%dmcolor\033[0m", color.red, color.green, color.blue);
		printf(" : r: %d g: %d b: %d\n", color.red, color.green, color.blue);
	}
	return (color_to_hex(color));
}

unsigned int	single_ray_cast(t_mlx *mlx, t_vec3 ray, t_vec3 offset, int print)
{
	t_vec3			dir;
	t_object_base	*target_obj;
	t_object_base	*intersect_obj;
	unsigned int	color[2];
	double			distance[2];

	distance[0] = INFINITY;
	color[0] = BACKGROUND;
	target_obj = mlx->scene->obj;
	dir = vec3_normalize(ray);
	intersect_obj = NULL;
	while (target_obj)
	{
		distance[1] = object_intersect(dir, target_obj, &color[1], offset);
		if ((distance[1] != NAN) && (distance[1] < distance[0]))
		{
			distance[0] = distance[1];
			color[0] = color[1];
			intersect_obj = target_obj;
		}
		target_obj = target_obj->next;
	}
	if (intersect_obj == NULL)
	{
		if (print)
			printf("background");
		return (BACKGROUND);
	}
	else
	{
		if (print)
		{
			if (intersect_obj->obj_type == E_CYLINDER)
				printf(" type : CYLINDER ");
			if (intersect_obj->obj_type == E_SPHERE)
				printf(" type : SPHERE ");
			if (intersect_obj->obj_type == E_PLANE)
				printf(" type : PLANE ");
			printf("\n\tray : [%f %f %f]", ray.x, ray.y, ray.z);
			printf("intersect!");
		}
		t_vec3	intersect;
		intersect = vec3_scale(ray, distance[0]);
		return (secondary_ray_cast(mlx, intersect, intersect_obj, print));
	}
}

/*
	mlx->scene->camera->hfov에 저장된 라디안 값을 이용해, 공간 상의 가상의 스크린까지의 거리를 구해야 한다.(카메라로 부터 스크린 까지 거리)
	tan(hfov / 2) = (mlx->width / 2) / depth. depth = (mlx->width / 2) / tan(hfov / 2) = mlx->width / 2 * atan(hfov / 2);
*/
void	ray_cast(t_mlx *mlx)
{
	unsigned int	x;
	unsigned int	y;
	double			d;
	unsigned int	color;
	t_vec3			ray;
	clock_t 		start, end;

	d = ((double)mlx->width / 2) / tan(mlx->scene->cam->hfov / 2);
	y = 0;
	start = clock();
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			ray = create_vec3((int)(x - mlx->width / 2), (int)(y - mlx->height / 2), d);
			color = single_ray_cast(mlx, vec3_normalize(ray), mlx->scene->cam->pos, 0);
			ft_mlx_set_pixel_color(mlx->image, x, y, color);
			x++;
		}
		y++;
	}
	end = clock();
	printf("time : %lu(ms)\n", ((end - start) / 1000));
}
