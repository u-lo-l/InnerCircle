/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:56:50 by dkim2             #+#    #+#             */
/*   Updated: 2022/08/01 00:27:46 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static unsigned char ft_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_color	hex_color(unsigned int hex_color)
{
	t_color	color;

	color.alpha = 0xff;
	color.red = ((hex_color >> 16) & 0xff);
	color.green = ((hex_color >> 8) & 0xff);
	color.blue = (hex_color & 0xff);
	return (color);
}

t_color rgb_color(unsigned int r, unsigned int g, unsigned int b)
{
	t_color	color;

	color.alpha = 0xff;
	color.red = ft_min(r, 0xff);
	color.green = ft_min(g, 0xff);
	color.blue = ft_min(b, 0xff);
	return (color);
}

t_color	color_add(t_color c1, t_color c2)
{
	c1.red = ft_min(0xff, (unsigned int)c1.red + (unsigned int)c2.red);
	c1.green = ft_min(0xff, (unsigned int)c1.green + (unsigned int)c2.green);
	c1.blue = ft_min(0xff, (unsigned int)c1.blue + (unsigned int)c2.blue);
	return (c1);
}

t_color color_scale(t_color c1, double s)
{
	if (s <= 0.0 || s >= 1.0)
		return (c1);
	c1.red *= s;
	c1.green *= s;
	c1.blue *= s;
	return (c1);
}

unsigned int color_to_hex(t_color c)
{
	unsigned int hex_color;

	hex_color = c.blue + (c.green << 8) + (c.red << 16);
	return (hex_color);
}
