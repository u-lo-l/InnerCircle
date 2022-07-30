/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:08:24 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/30 22:48:12 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/scene.h"
#include "../INC/mlx_part.h"
#include "../Libft_vector/vector3.h"
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

// static unsigned int secondary_ray_cast(t_mlx *mlx, t_vec3 ray, t_vec3 offset)
// {
	
// }

static unsigned int	single_ray_cast(t_mlx *mlx, t_vec3 ray, t_vec3 offset)
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
	// intersect_obj = NULL;
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
	
	return (color[0]);
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
			color = single_ray_cast(mlx, ray, mlx->scene->cam->pos);
			ft_mlx_set_pixel_color(mlx->image, x, y, color);
			x++;
		}
		y++;
	}
	end = clock();
	printf("time : %lu(ms)\n", ((end - start) / 1000));
}
