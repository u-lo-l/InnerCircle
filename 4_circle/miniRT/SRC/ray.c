/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:08:24 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/26 14:51:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/scene.h"
#include "../INC/mlx_part.h"
#include "../Libft_vector/vector3.h"
#include <stdlib.h>
#include <math.h>

t_ray	*create_ray(t_vec3 *org, t_vec3 *dir)
{
	return (NULL);
}

void	free_raylst(t_ray **pray)
{
	t_ray	*curr;
	t_ray	*next;

	curr = *pray;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(*pray);
	*pray = NULL;
}


static unsigned int single_ray_cast(t_mlx *mlx, unsigned int x, unsigned int y, double depth)
{
	t_vec3			dir;
	t_object_base	*target_obj;
	unsigned int	color;
	double			distance;
	
	target_obj = mlx->scene->obj;
	dir = create_vec3(x, y, depth);
	while (target_obj)
	{
		target_obj = target_obj->next;
	}
	return (color);
}

/*
	mlx->scene->camera->hfov에 저장된 라디안 값을 이용해, 공간 상의 가상의 스크린까지의 거리를 구해야 한다.(카메라로 부터 스크린 까지 거리)
	tan(hfov / 2) = (mlx->width / 2) / depth. depth = (mlx->width / 2) / tan(hfov / 2) = mlx->width / 2 * atan(hfov / 2);
*/
int	ray_cast(t_mlx *mlx)
{
	int		x;
	int		y;
	double	d;

	d = ((double)mlx->width / 2) * atan(mlx->scene->cam->hfov / 2);
	y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
		{
			
		}
	}
}