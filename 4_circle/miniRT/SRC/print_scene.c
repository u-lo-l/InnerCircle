/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:11:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/07 22:50:00 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/scene.h"
#include "../LIBFT/libft.h"

static void	put_double_prec4(double num)
{
	ft_putnbr_fd((int)num, 1);
	ft_putchar_fd('.', 1);
	ft_putnbr_fd((int)((int)(num * 10000) % 10000), 1);
}

void	info_light(t_light *light)
{
	ft_putstr_fd("[LIGHT]\n", 1);
	ft_putstr_fd("\tpos : [", 1);
	put_double_prec4(light->org.x);
	ft_putstr_fd(", ", 1);
	put_double_prec4(light->org.y);
	ft_putstr_fd(", ", 1);
	put_double_prec4(light->org.z);
	ft_putstr_fd("]\n", 1);
	ft_putstr_fd("\tbrightness : ", 1);
	put_double_prec4(light->bright);
	ft_putstr_fd("\n", 1);
	if (light->next)
		info_light(light->next);
}

void	info_camera(t_cam *cam)
{
	ft_putstr_fd("[CAMERA]\n", 1);
	ft_putstr_fd("\tpos : [", 1);
	put_double_prec4(cam->pos.x);
	ft_putstr_fd(", ", 1);
	put_double_prec4(cam->pos.y);
	ft_putstr_fd(", ", 1);
	put_double_prec4(cam->pos.z);
	ft_putstr_fd("]\n", 1);
	ft_putstr_fd("\tdir : [", 1);
	put_double_prec4(cam->dir.x);
	ft_putstr_fd(", ", 1);
	put_double_prec4(cam->dir.y);
	ft_putstr_fd(", ", 1);
	put_double_prec4(cam->dir.z);
	ft_putstr_fd("]\n", 1);
	ft_putstr_fd("\tHFOV : ", 1);
	put_double_prec4(cam->hfov);
	ft_putstr_fd("(deg)\n", 1);
}

void	info_scene(t_scene *scene)
{
	info_light(scene->light);
	ft_putstr_fd("[AMBIENT]\n", 1);
	ft_putstr_fd("\tratio : ", 1);
	put_double_prec4(scene->ambient_ratio);
	ft_putstr_fd("\n\tcolor : ", 1);
	ft_putnbr_fd((scene->ambient_color >> 16) & 0xff, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd((scene->ambient_color >> 8) & 0xff, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd((scene->ambient_color) & 0xff, 1);
	ft_putstr_fd("\n", 1);
	info_camera(scene->cam);
	ft_putstr_fd("[OBJECTS]\n", 1);
	info_object(scene->obj);
}
