#include "../INC/fdf.h"

void print_33mat(t_33mat mat)
{
	int i = 0;
	while (i < 3)
	{
		int j = 0;
		while (j < 3)
		{
			printf(" %3.2f", mat[j][i]);
			j++;
		}
		printf("\n");
		i++;
	}
}
void print_dvec3(t_dvec3 vec3)
{
	printf("%3.2f\n%3.2f\n%3.2f\n", vec3[X], vec3[Y], vec3[Z]);
}

void		print_output_map(t_outputmap *map)
{
	int	x;
	int	y;

	if (!map)
		return ;
	printf("SIZE\n");
	printf("Y(width) : %d X(height) : %d\n", map->sizeof_y, map->sizeof_x);
	printf("MAX & MIN\n");
	printf("(y,x) | (%d, %d)~(%d,%d)\n", map->minpoint[Y], map->minpoint[X], \
			map->maxpoint[Y], map->maxpoint[X]);
	printf("DEFALT OFFSET\n");
	printf("Y OFFSET : %d X_OFFSET %d\n", map->offset_default[Y], map->offset_default[X]);
	x = -1;
	while (++x < map->sizeof_x)
	{
		y = -1;
		while (++y < map->sizeof_y)
			printf("(%3.2f %3.2f | %#x)", map->map[x][y][0], map->map[x][y][1], (int)map->map[x][y][2]);
		printf("\n");
	}
}
/* maxtix check
int main()
{
	t_33mat	mat;
	t_dvec3	axis;
	t_dvec3 vec1;
	t_dvec3 vec2;
	int res;

	if (zero_33mat(mat) == FALSE)
		return (0);
	print_33mat(mat);
	if (!get_unitvector(0, 0, 1, axis))
		return (0);
	print_dvec3(axis);
	if (!rotation_matrix(axis, 3.14 / 3, mat))
		return (0);
	print_33mat(mat);
	if (!get_unitvector(0, 1, 0, vec1))
		return (0);
	print_dvec3(vec1);
	if (!transform(vec1,mat,vec2))
		return (0);
	print_dvec3(vec2);
}*/

int 	main(int argc, char ** argv)
{
	t_inputmap *in = get_origin_map(argv[argc - 1]);
	
	if (in == NULL)
	{
		printf("ERROR\n");
		return (0);
	}
	print_orgmap(in);
	printf("Y X | %d %d\n", in->sizeof_y, in->sizeof_x);
	t_outputmap	*out = create_ouputmap(in->sizeof_y, in->sizeof_x);
	printf("Y X | %d %d\n", out->sizeof_y, out->sizeof_x);
	if (!out)
	{
		delete_map_org(in);
		return (0);
	}
	t_33mat rot;
	t_dvec3 u;
	t_dvec3 v;
	t_dvec3 w;

	get_unitvector(1,1,-2,u);
	get_unitvector(-1,1,0,v);
	get_unitvector(1,1,1,w);
	tranformation_33mat(rot, u, v, w);
	print_33mat(rot);
	if (!convert_map(in, rot, out))
		return (0);
	print_output_map(out);
	set_outputmap_size(out);
	print_output_map(out);

}