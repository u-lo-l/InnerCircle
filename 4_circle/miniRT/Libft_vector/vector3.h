/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 07:02:15 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 07:39:36 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_vec3
{
	double				x;
	double				y;
	double				z;
}	t_vec3;

t_vec3	*create_vec3(double x, double y, double z);
void	free_vec3(t_vec3 **pvec_3);

double	vec3_l2norm(t_vec3 *a);
t_vec3	*vec3_normalize(t_vec3 *a);

t_vec3	*vec3_add(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_subtract(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_scale(t_vec3 *a, double scaler);
double	vec3_dot(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_cross(t_vec3 *a, t_vec3 *b);

#endif