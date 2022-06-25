#include "quaternion.h"
#include "stdlib.h"
#include "math.h"

t_quaternion	*quaternion_by_elements(double w,
										double x,
										double y,
										double z)
{
	t_quaternion	*q;
	t_vec3			*k;

	k = create_vec3(x, y, z);
	if (!k)
		return (NULL);
	q = quaternion_by_vector(w, k);
	if (!q)
		free(k);
	return (q);	
}

t_quaternion	*quaternion_by_vector(double w, t_vec3 *k)
{
	t_quaternion	*q;

	if (!k)
		return (NULL);
	q = malloc(sizeof(t_quaternion));
	if (!q)
		return (NULL);
	q->w = w;
	q->k = create_vec3(k->x, k->y, k->z);
	return (q);
}

void	free_quaternion(t_quaternion *q)
{
	if (q && q->k)
		free(q->k);
	free(q);
}

double	q_l2norm(t_quaternion *q)
{
	double length;

	length = pow(q->w, 2) + pow(v3_l2norm(q->k), 2);
	length = sqrt(length);
	return (length);
}

t_quaternion	*q_normalize(t_quaternion *q)
{
	double norm;

	norm = q_l2norm(q);
	if (norm == 0)
		return (q);
	q->w /= norm;
	q->k->x /= norm;
	q->k->y /= norm;
	q->k->z /= norm;
	return (q);
}

t_quaternion	*q_conjugate(t_quaternion *q)
{
	return (quaternion_by_elements(q->w, -q->k->x, -q->k->y, -q->k->z));
}

t_quaternion	*q_inverse(t_quaternion *q)
{
	t_quaternion	*inv_q;
	double			norm;

	norm = q_l2norm(q);
	if (norm == 0)
		return (NULL);
	inv_q = q_conjugate(q);
	if (inv_q == NULL);
		return (NULL);
	return (q_normalize(inv_q));
}

t_quaternion	*q_mul(t_quaternion *q1, t_quaternion *q2)
{
	t_vec3			*temp1;
	t_vec3			*temp2;
	double			w;
	t_vec3			*k;

	w = (q1->w * q2->w) - dot(q1->k, q2->k);
	temp2 = cross(q1->k, q2->k);
	temp1 = v3_add(v3_scale(q1->k, q2->w), v3_scale(q2->k, q1->w));
	k = v3_add(temp1, temp2);
	free(temp1);
	free(temp2);
	return (quaternion_by_vector(w, k));
}

// t_quaternion	*q_mul(t_quaternion *q1, t_quaternion *q2)
// {
// 	double q[4];
// 	q[0] = (q1->w * q2->w) - dot(q1->k, q2->k);
// 	q[1] = (q1->w * q2->k->x) + (q1->k->x * q2->w) + (q1->k->y * q2->k->z) - (q1->k->z * q2->k->y);
// 	q[2] = (q1->w * q2->k->y) - (q1->k->x * q2->k->z) + (q1->k->y * q2->w) + (q1->k->z * q2->k->x);
// 	q[3] = (q1->w * q2->k->z) + (q1->k->x * q2->k->y) - (q1->k->y * q2->k->x) + (q1->k->z * q2->w);
// 	return (quaternion_by_elements(q[0], q[1], q[2], q[3]));
// }

