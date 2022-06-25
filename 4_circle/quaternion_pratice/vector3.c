#include "vector3.h"
#include <math.h>
#include <stdlib.h>

t_vec3	*zero_vec3(void)
{
	t_vec3 *zero;

	zero = malloc(sizeof(t_vec3));
	if (!zero)
		return (NULL);
	zero->x = 0.0;
	zero->y = 0.0;
	zero->z = 0.0;
	return (zero);
}

t_vec3	*create_vec3(double x, double y, double z)
{
	t_vec3 *vec;

	vec = malloc(sizeof(t_vec3));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

double	v3_l2norm(t_vec3 *a)
{
	double	length;

	length = pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2);
	length = sqrt(length);
	return (length);
}

t_vec3	*v3_normalize(t_vec3 *a)
{
	double length;
	
	length = v3_l2norm(a);
	if (!length)
		return (a);
	a->x /= length;
	a->y /= length;
	a->z /= length;
	return (a);
}

t_vec3	*v3_add(t_vec3 *a, t_vec3 *b)
{
	return (create_vec3(a->x + b->x, a->y + b->y, a->z + b->z));
}

t_vec3 *v3_scale(t_vec3 *a, double s)
{
	if (!a)
		return (NULL);
	a->x *= s;
	a->y *= s;
	a->z *= s;
	return (a);
}

double	dot(t_vec3	*a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec3	*cross(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*cross_vec;
	double	x;
	double	y;
	double	z;

	x = a->y * b->z - a->z * b->y;
	y = a->z * b->x - a->x * b->z;
	z = a->x * b->y - a->y * b->x;
	return (create_vec3(x, y, z));
}
