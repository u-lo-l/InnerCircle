/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 07:30:41 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 08:04:19 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H
# include "vector3.h"

typedef struct s_quat
{
	double	w;
	t_vec3	*k;
}	t_quat;

t_quat	*quat_by_elements(double x, double y, double z, double w);

t_quat	*quat_by_vector(double w, t_vec3 *k);

void	free_quat(t_quat **pquat);

t_quat	*quat_normalize(t_quat *quat);

t_quat	*quat_conjugate(t_quat *quat);

t_quat	*quat_inverse(t_quat *quat);

double	quat_l2norm(t_quat *quat);

t_quat	*quat_mul(t_quat *quat1, t_quat *qaut2);

#endif