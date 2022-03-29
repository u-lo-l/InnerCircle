#include "matrix.h"


t_matrix	*screw_symetric_matrix(double*	vec3)
{
	t_matrix	*screw_symetric;

	screw_symetric = init_zero_matrix(4, 4);
	if (screw_symetric == NULL)
		return (NULL);
	screw_symetric->mat[0][1] = vec3[Z];
	screw_symetric->mat[0][2] = -vec3[Y];
	screw_symetric->mat[1][0] = -vec3[Z];
	screw_symetric->mat[1][2] = vec3[X];
	screw_symetric->mat[2][0] = vec3[Y];
	screw_symetric->mat[2][1] = -vec3[X];
	screw_symetric->mat[3][3] = 1;
	return (screw_symetric);
}

t_matrix	*rotation_matrix_rodrigue(t_matrix *axis_vec, double rad)
{
	t_matrix	*rot;
	t_matrix	*screw_sym;
	t_matrix	*screw_sym2;
	rot = init_unit_matrix(4, 4);
	if (rot == NULL)
		return (NULL);
	screw_sym = screw_symetric_matrix(axis_vec->mat[0]);
	screw_sym2 = mat_mul(screw_sym, screw_sym);
	if (screw_sym && screw_sym2)
	{
		mat_scale(screw_sym, sin(rad));
		mat_scale(screw_sym2, 1 - cos(rad));
		mat_sum(rot, screw_sym);
		mat_sum(rot, screw_sym2);
	}
	else
		destroy_matrix(rot);
	destroy_matrix(screw_sym);
	destroy_matrix(screw_sym2);
	return (rot);
}

t_matrix	*rotation_to_view_cords(t_matrix *view_xyz)
{

}

t_matrix	*transformation_matrix(t_matrix *rotaion, t_matrix *traslation)
{

}