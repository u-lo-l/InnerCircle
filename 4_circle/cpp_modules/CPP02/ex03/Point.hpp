/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:19:31 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 21:19:25 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
	Fixed _x;
	Fixed _y;
public:
	Point();
	Point(float a, float b);
	~Point();
	Point(const Point & p);

	Fixed	getX() const;
	Fixed	getY() const;

	// Point operator+(const Point & p);
	Point operator-(const Point & p) const;
	Point & operator=(const Point & p);
	bool operator!=(const Point & p);
	bool operator==(const Point & p);
};

std::ostream & operator<<(std::ostream & os, const Point & c);

bool	bsp(Point const a, Point const b, Point const c,
			Point const point);

#endif