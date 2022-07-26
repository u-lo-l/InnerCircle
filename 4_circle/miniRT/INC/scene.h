/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:08:22 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/26 15:37:08 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "../Libft_vector/matrix33.h"

# ifndef TRUE
# 	define TRUE (1)
# endif
# ifndef FALSE
#  define FALSE (0)
# endif
# define T_PLANE ("plane")
# define T_SPHERE ("sphere")
# define T_CYLINDER ("cylinder")

typedef struct s_ray	t_ray;
struct s_ray
{
	t_vec3	org;
	t_vec3	dir;
	t_ray	*next;
};

/*
  plane		-> type : plane		| radius = 0 | height = 0
  sphere	-> type : sphere	| radius = r | height = 0
  cylinder	-> type : cylinder	| radius = r | height = h
*/
typedef struct s_object_base	t_object_base;
struct s_object_base
{
	char			*type;
	unsigned int	color;
	double			radius;
	double			height;
	t_vec3			org;
	t_vec3			normal;
	t_object_base	*next;
};

typedef struct s_light	t_light;
struct s_light
{
	t_vec3	org;
	double	bright;
	t_light	*next;
};

typedef struct s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	double	hfov;
}	t_cam;

typedef struct s_scene
{
	double			ambient_ratio;
	unsigned int	ambient_color;
	t_cam			*cam;
	t_mat33			global;
	t_light			*light;
	t_object_base	*obj;
}	t_scene;

/*=====RAY=====*/
t_ray	*create_ray(t_vec3 org, t_vec3 dir);
void	free_raylst(t_ray **pray);

/*=====LIGHT=====*/
t_light	*create_light(t_vec3 pos, double b);
void	free_lightlst(t_light *l);
int		case_light(t_scene *scene, char **single_scene);
int		case_ambient(t_scene *scene, char **single_scene);

/*=====CAMERA=====*/
int		case_camera(t_scene *scene, char **single_scene);

/*=====OBJECTS=====*/
void	free_objectlst(t_object_base *objlst);
int		case_sphere(t_scene *scene, char **single_scene);
int		case_plane(t_scene *scene, char **single_scene);
int		case_cylinder(t_scene *scene, char **single_scene);

/*=====SCENES=====*/
t_scene	*create_empty_scene(void);
void	free_scene(t_scene *pscene);
int		transform_to_cam_cord(t_scene *scene);

//read_scene
int		init_scene(t_scene *scene, char *filename);

/*=====UTILS=====*/
int		str_to_vec3(char *str, t_vec3 *v);
int		str_to_color(char *str, unsigned int *color);

/*=====PRINT SCENE====*/
void	info_light(t_light *light);
void	info_camera(t_cam *cam);
void	info_object(t_object_base *obj);
void	info_scene(t_scene *scene);

/*=====INTERSECT=====*/
double object_intersect(t_vec3 ray, t_object_base * obj, unsigned int * pcolor);

#endif