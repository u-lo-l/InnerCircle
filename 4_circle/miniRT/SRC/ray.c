/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:08:24 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 09:14:07 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ray.h"
#include <stdlib.h>

t_ray	*set_ray(t_vec3 *org, t_vec3 *dir)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->org = org;
	ray->dir = dir;
	ray->next = NULL;
	return (ray);
}

void	**free_ray(t_ray **pray)
{
	free((*pray)->org);
	free((*pray)->dir);
	free(*pray);
	*pray = NULL;
}