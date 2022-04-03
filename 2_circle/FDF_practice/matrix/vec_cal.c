#include "matrix.h"

double	l2_norm(t_matrix *vec)
{
	double	euclidean_norm;
	int 	r;
	if (!vec)
		return (NAN);
	r = -1;
	euclidean_norm = 0;
	while (++r < vec->dim[0])
		euclidean_norm += pow(vec->mat[r][0], 2);
	euclidean_norm = sqrt(euclidean_norm);
	return (euclidean_norm);
}

double	vec_dot(double *vec_1, double *vec_2, int size)
{
	double	result;
	int		i;

	if (!vec_1 || !vec_2)
		return (NAN);
	i = 0;
	result = 0;
	while (i < size)
	{
		result += vec_1[i] * vec_2[i];
		i++;
	}
	return (result);
}

t_matrix	*unit_vec(t_matrix *vec)
{
	t_matrix	*unit;
	double		norm;
	double		i;
	double		j;
	double		k;

	if (!vec || (vec->dim[1] > 1))
		return (NULL);
	norm = l2_norm(vec);
	if (norm == NAN || 1 / norm == INFINITY)
		return (NULL);
	i = vec->mat[0][0] / norm;
	j = vec->mat[1][0] / norm;
	k = vec->mat[2][0] / norm;
	unit = init_3d_vec(i, j, k);
	return (unit);
}