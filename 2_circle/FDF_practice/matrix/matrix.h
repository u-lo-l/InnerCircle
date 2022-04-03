#ifndef MATRIX_H
# define MATRIX_H
# define TRUE 1
# define FALSE 0
# define X 0
# define Y 1
# define Z 2
# define W 3
# include <math.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct	s_matrix_type
{
	int		dim[2];
	double	**mat;
}			t_matrix;

void		print_matrix(t_matrix *a);

/*matrix*/
t_matrix	*init_matrix(int rows, int cols);
void		destroy_matrix(t_matrix *matrix);
t_matrix	*init_zero_matrix(int rows, int cols);
t_matrix	*init_unit_matrix(int rows, int cols);
t_matrix	*init_3d_vec(double x, double y, double z);

/*matrix2*/
t_matrix	*mat_mini(t_matrix *a, int row, int col);
double		mat_determinant(t_matrix *a);
t_matrix	*mat_transpose(t_matrix *a);
t_matrix	*mat_inverse(t_matrix *a);

/*cal1*/
int			mat_sum(t_matrix *target, t_matrix *b);
int			mat_sub(t_matrix *target, t_matrix *b);
t_matrix	*mat_mul(t_matrix *a, t_matrix *b);
int			mat_scale(t_matrix *a, double scaler);

/*vec_cal*/
double		l2_norm(t_matrix *vec);
double		vec_dot(double *vec_1, double *vec_2, int size);
t_matrix	*unit_vec(t_matrix *vec);

/*transformation matrix*/
t_matrix	*cross_matrix(double	vec3[3]);
t_matrix	*rotation_matrix_rodrique(t_matrix *axis_vec, double rad);
t_matrix	*rotation_to_view_cords(t_matrix *view);
t_matrix	*transformation_matrix(t_matrix *rotaion, t_matrix *traslation);


#endif