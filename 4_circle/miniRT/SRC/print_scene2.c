/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:20:28 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/08 06:32:27 by dkim2            ###   ########.fr       */
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

static void	info_plane(t_object_base *obj)
{
	ft_putstr_fd("\tnormal : [", 1);
	put_double_prec4(obj->normal.x);
	ft_putstr_fd(", ", 1);
	put_double_prec4(obj->normal.y);
	ft_putstr_fd(", ", 1);
	put_double_prec4(obj->normal.z);
	ft_putstr_fd("]\n", 1);
	ft_putstr_fd("\tcolor : ", 1);
	ft_putnbr_fd((obj->color >> 16) & 0xff, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd((obj->color >> 8) & 0xff, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd((obj->color) & 0xff, 1);
	ft_putstr_fd("\n\n", 1);
}

static void	info_sphere(t_object_base *obj)
{
	ft_putstr_fd("\tradius : ", 1);
	put_double_prec4(obj->radius);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\tcolor : ", 1);
	ft_putnbr_fd((obj->color >> 16) & 0xff, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd((obj->color >> 8) & 0xff, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd((obj->color) & 0xff, 1);
	ft_putstr_fd("\n\n", 1);
}

static void	info_cylinder(t_object_base *obj)
{
	ft_putstr_fd("\tnormal : [", 1);
	put_double_prec4(obj->normal.x);
	ft_putstr_fd(", ", 1);
	put_double_prec4(obj->normal.y);
	ft_putstr_fd(", ", 1);
	put_double_prec4(obj->normal.z);
	ft_putstr_fd("]\n", 1);
	ft_putstr_fd("\tradius : ", 1);
	put_double_prec4(obj->radius);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\theight : ", 1);
	put_double_prec4(obj->height);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\tcolor : ", 1);
	ft_putnbr_fd((obj->color >> 16) & 0xff, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd((obj->color >> 8) & 0xff, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd((obj->color) & 0xff, 1);
	ft_putstr_fd("\n\n", 1);
}

void	info_object(t_object_base *obj)
{
	if (obj == NULL)
		ft_putstr_fd("FUCK\n", 1);
	ft_putstr_fd("\ttype : ", 1);
	ft_putstr_fd(obj->type, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\torg : [", 1);
	put_double_prec4(obj->org.x);
	ft_putstr_fd(", ", 1);
	put_double_prec4(obj->org.y);
	ft_putstr_fd(", ", 1);
	put_double_prec4(obj->org.z);
	ft_putstr_fd("]\n", 1);
	if (!ft_strncmp(obj->type, T_PLANE, ft_strlen(T_PLANE) + 1))
		info_plane(obj);
	else if (!ft_strncmp(obj->type, T_SPHERE, ft_strlen(T_SPHERE) + 1))
		info_sphere(obj);
	else if (!ft_strncmp(obj->type, T_CYLINDER, ft_strlen(T_CYLINDER) + 1))
		info_cylinder(obj);
	if (obj->next)
		info_object(obj->next);
}
