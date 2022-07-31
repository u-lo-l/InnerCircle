/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:31:17 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/31 23:58:27 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/mlx_part.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int	keydown(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		delete_mlx(mlx);
		exit(0);
	}
	return (0);
}

int	destroy(t_mlx *mlx)
{
	if (!mlx)
		return (0);
	delete_mlx(mlx);
	exit(0);
}

int mousedown(int button, int x, int y, t_mlx *mlx)
{
	double			d;
	t_vec3			ray;

	if (!mlx)
		return (0);
	if (button == 1)
	{
		printf("[%u, %u] : ", x, y);	
		d = ((double)mlx->width / 2) / tan(mlx->scene->cam->hfov / 2);
		ray = create_vec3((int)(x - mlx->width / 2), (int)(y - mlx->height / 2), d);
		single_ray_cast(mlx, vec3_normalize(ray), create_vec3(0,0,0), 1);
		printf("\n");
	}
	return (0);
}