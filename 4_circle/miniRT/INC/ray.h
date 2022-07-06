/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:02:51 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 08:31:50 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "../Libft_vector/vector3.h"

typedef struct s_ray
{
	t_vec3			*org;
	t_vec3			*dir;
	struct s_ray	*next;
}	t_ray;

t_ray	*set_ray(t_vec3 *org, t_vec3 *dir);
void	**free_ray(t_ray **pray);

#endif