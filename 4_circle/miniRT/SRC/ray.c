/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:08:24 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/07 22:17:56 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/ray.h"
#include <stdlib.h>

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
