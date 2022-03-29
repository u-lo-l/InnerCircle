#include "matrix.h"

int	mat_sum(t_matrix *target, t_matrix *b)
{
	int			r;
	int			c;

	if (!target || !b)
		return (FALSE);
	if ((target->dim[0] != b->dim[0]) || (target->dim[1] != b->dim[1]))
		return (FALSE);
	r = -1;
	while (++r < target->dim[0])
	{
		c = -1;
		while (++c < target->dim[1])
			target->mat[r][c] += b->mat[r][c];
	}
	return (TRUE);
}

int	mat_sub(t_matrix *target, t_matrix *b)
{
	int			r;
	int			c;

	if (!target || !b)
		return (FALSE);
	if ((target->dim[0] != b->dim[0]) || (target->dim[1] != b->dim[1]))
		return (FALSE);
	r = -1;
	while (++r < target->dim[0])
	{
		c = -1;
		while (++c < target->dim[1])
			target->mat[r][c] -= b->mat[r][c];
	}
	return (TRUE);
}

t_matrix	*mat_mul(t_matrix *a, t_matrix *b)
{
	t_matrix	*trans;
	t_matrix	*result;
	int			c;
	int			r;

	if (a->dim[1] != b->dim[0])
		return (NULL);
	trans = mat_transpose(a);
	if (!trans)
		return (NULL);
	result = init_matrix(a->dim[0], b->dim[1]);
	c = -1;
	while (result != NULL && ++c < result->dim[1])
	{
		r = -1;
		while (++r < result->dim[0])
			result->mat[c][r] = vec3_dot(trans->mat[r], b->mat[c]);
	}
	destroy_matrix(trans);
	return (result);
}

int		mat_scale(t_matrix *a, double scaler)
{
	int			r;
	int			c;

	if (!a || scaler == INFINITY)
		return (FALSE);
	r = -1;
	while (++r < a->dim[0])
	{
		c = -1;
		while (++c <a->dim[1])
			a->mat[r][c] = a->mat[r][c] * scaler;
	}
	return (TRUE);
}