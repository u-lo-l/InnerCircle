/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:08:22 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/06 09:31:11 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "../Libft_vector/vector3.h"
# define T_LIGHT = "light"
# define T_PLANE = "plane"
# define T_CIRCLE = "circle"
# define T_SPHERE = "sphere"
# define T_CYLINDER = "cylinder"

typedef struct s_ray			t_ray;
typedef struct s_ray
{
	t_vec3	*org;
	t_vec3	*dir;
	t_ray	*next;
}	t_ray;

t_ray	*set_ray(t_vec3 *org, t_vec3 *dir);
void	**free_ray(t_ray **pray);

/*
  plane		-> type : plane		| radius = 0 | height = 0
  circle	-> type : circle	| radius = r | height = 0
  sphere	-> type : sphere	| radius = r | height = 0
  cylinder	-> type : cylinder	| radius = r | height = h
*/
typedef struct s_object_base	t_object_base;
struct s_object_base
{
	char			*type;
	double			radius;
	double			height;
	t_vec3			*org;
	t_vec3			*normal;
	t_object_base	*next;
};

typedef struct s_scene
{
	t_vec3			*light_org;
	t_vec3			*cam_org;
	t_vec3			*cam_dir;
	double			light_brightness;
	double			ambient_ratio;
	int				ambient_color;
	t_object_base	*first;
}	t_scene;

t_scene	*create_empty_scene(void);
void	free_scene(t_scene **pscene);
int		set_light(t_scene *scene, t_vec3 *org, double b);
int		set_ambient(t_scene *scene, double r, int c);
int		set_cam(t_scene *scene, t_vec3 *pos, t_vec3 *dir);

#endif