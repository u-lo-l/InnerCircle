#include "matrix.h"


t_matrix	*cross_matrix(double*	vec3)
{
	t_matrix	*cross_matrix;

	cross_matrix = init_zero_matrix(4, 4);
	if (cross_matrix == NULL)
		return (NULL);
	cross_matrix->mat[0][1] = vec3[Z];
	cross_matrix->mat[0][2] = -vec3[Y];
	cross_matrix->mat[1][0] = -vec3[Z];
	cross_matrix->mat[1][2] = vec3[X];
	cross_matrix->mat[2][0] = vec3[Y];
	cross_matrix->mat[2][1] = -vec3[X];
	cross_matrix->mat[3][3] = 1;
	return (cross_matrix);
}

t_matrix	*rotation_matrix_rodrigue(t_matrix *axis_vec, double rad)
{
	t_matrix	*rot;
	t_matrix	*cross_mat;
	t_matrix	*cross_mat2;
	rot = init_unit_matrix(4, 4);
	if (rot == NULL)
		return (NULL);
	cross_mat = cross_matrix(axis_vec->mat[0]);
	cross_mat2 = mat_mul(cross_mat, cross_mat);
	if (cross_mat && cross_mat2)
	{
		mat_scale(cross_mat, sin(rad));
		mat_scale(cross_mat2, 1 - cos(rad));
		mat_sum(rot, cross_mat);
		mat_sum(rot, cross_mat2);
	}
	else
		destroy_matrix(rot);
	destroy_matrix(cross_mat);
	destroy_matrix(cross_mat2);
	return (rot);
}

t_matrix	*rotation_to_view_cords(t_matrix *view_xyz)
{

}

t_matrix	*transformation_matrix(t_matrix *rotation, t_matrix *translation)
{
	int			rot_mat_dim;
	int			translation_dim;
	t_matrix	*transform;

	if (rotation == NULL)
		rot_mat_dim = 0;
	else if (rotation->dim[0] == rotation->dim[1]) 
		rot_mat_dim = rotation->dim[0];
	else
		return (NULL);
	if (translation == NULL)
		translation_dim = translation->dim[0];
	if (rot_mat_dim != translation_dim)
		return (NULL);
	transform = init_zero_matrix(rot_mat_dim + 1, rot_mat_dim + 1);
}