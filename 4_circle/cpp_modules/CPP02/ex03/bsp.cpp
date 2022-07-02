/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:19:36 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 22:49:54 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c,
			Point const p)
{
	Point	vecA, vecB;
	Fixed 	u, v, d;

	vecA = b - a;
	vecB = c - a;
	d = vecA.getX() * vecB.getY() - vecA.getY() * vecB.getX();
	u = p.getX() * vecB.getY() - p.getY() * vecB.getX();
	v = p.getY() * vecA.getX() - p.getX() * vecA.getY();
	u = u / d;
	v = v / d;
	if (Fixed(0) < u && u < Fixed(1) && \
		Fixed(0) < v && v < Fixed(1) && \
		u + v < Fixed(1))
		return (true);
	return (false);
}