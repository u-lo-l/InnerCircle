#include "quaternion.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_vec3	*rotate(t_vec3 *p, t_vec3 *axis, double deg)
{
	double theta = deg / 180 * M_PI;
	t_vec3 *v_temp = v3_normalize(axis);
	t_quaternion	*q_temp[3];
	t_quaternion 	*q;
	t_quaternion 	*q_c;

	q = quaternion_by_vector(cos(theta / 2), v3_scale(v_temp, sin(theta / 2)));
	printf("q : [%3.3f, %3.3f, %3.3f, %3.3f]\n", q->w, q->k->x, q->k->y, q->k->z);

	q_c = q_conjugate(q);
	printf("q_c : [%3.3f, %3.3f, %3.3f, %3.3f]\n", q_c->w, q_c->k->x, q_c->k->y, q_c->k->z);


	q_temp[0] = quaternion_by_vector(0, p);
	printf("q0 : [%3.3f, %3.3f, %3.3f, %3.3f]\n", q_temp[0]->w, q_temp[0]->k->x, q_temp[0]->k->y, q_temp[0]->k->z);

	q_temp[1] = q_mul(q, q_temp[0]);
	printf("q1 : [%3.3f, %3.3f, %3.3f, %3.3f]\n", q_temp[1]->w, q_temp[1]->k->x, q_temp[1]->k->y, q_temp[1]->k->z );

	q_temp[2] = q_mul(q_temp[1], q_c);
	printf("q2 : [%3.3f, %3.3f, %3.3f, %3.3f]\n", q_temp[2]->w, q_temp[2]->k->x, q_temp[2]->k->y, q_temp[2]->k->z );

	v_temp = create_vec3(q_temp[2]->k->x, q_temp[2]->k->y, q_temp[2]->k->z);

	free_quaternion(q);
	free_quaternion(q_c);
	free_quaternion(q_temp[0]);
	free_quaternion(q_temp[1]);
	free_quaternion(q_temp[2]);
	return (v_temp);
}

int main()
{
	t_vec3 *X = create_vec3(1, 0, 0);
	t_vec3 *Y = create_vec3(0, 1, 0);
	t_vec3 *Z = create_vec3(0, 0, 1);

	t_vec3 *P = create_vec3(10, 0, 0);
	printf("P : [%3.3f, %3.3f, %3.3f]\n",P->x, P->y, P->z);

	t_vec3 *Q = rotate(P, Z, 30);
	printf("P : [%3.3f, %3.3f, %3.3f] Q : [%3.3f, %3.3f, %3.3f]\n",
			P->x, P->y, P->z, Q->x, Q->y, Q->z);

	printf("\n\n\n");
	t_vec3 *C = cross(Y, X);
	printf("j_hat cross i_hat -> ");
	printf("C : [%3.3f, %3.3f, %3.3f]\n",C->x, C->y, C->z);
}
