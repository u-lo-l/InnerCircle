#ifndef QUATERNION_H
# define QUATERNION_H
# include "vector3.h"

typedef struct s_quaternion
{
	double	w;
	t_vec3	*k;
}	t_quaternion;

t_quaternion	*quaternion_by_elements(double x, 
										double y,
										double z,
										double w);
t_quaternion	*quaternion_by_vector(double w, t_vec3 *k);
void			free_quaternion(t_quaternion *q);
t_quaternion	*q_normalize(t_quaternion *q);
t_quaternion	*q_conjugate(t_quaternion *q);
t_quaternion	*q_inverse(t_quaternion *q);
double			q_l2norm(t_quaternion *q);
t_quaternion	*q_mul(t_quaternion *q1, t_quaternion *q2);

#endif
