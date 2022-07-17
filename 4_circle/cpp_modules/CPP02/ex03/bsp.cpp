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

bool	bsp(Point const & a, Point const & b, Point const & c,
			Point const & p)
{
	Point	vecA, vecB, p_2;
	Fixed 	u, v, d;

	vecA = b - a;
	vecB = c - a;
	p_2 = p - a;
	d = vecA.getX() * vecB.getY() - vecA.getY() * vecB.getX();
	u = p_2.getX() * vecB.getY() - p_2.getY() * vecB.getX();
	v = p_2.getY() * vecA.getX() - p_2.getX() * vecA.getY();
	u = u / d;
	v = v / d;
	std::cout << "u : " << u << std::endl;
	std::cout << "v : " << v << std::endl;
	if (Fixed(0) < u && u < Fixed(1) && \
		Fixed(0) < v && v < Fixed(1) && \
		(u + v) < Fixed(1))
		return (true);
	return (false);
}
