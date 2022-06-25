#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_vec3
{
	double x;
	double y;
	double z;
}	t_vec3;

t_vec3	*zero_vec3(void);
t_vec3	*create_vec3(double x, double  y, double z);
double	v3_l2norm(t_vec3 *a);
t_vec3	*v3_normalize(t_vec3 *a);
t_vec3	*v3_add(t_vec3 *a, t_vec3 *b);
t_vec3	*v3_scale(t_vec3 *a, double scaler);
double	dot(t_vec3 *a, t_vec3 *b);
t_vec3	*cross(t_vec3 *a, t_vec3 *b);

#endif
