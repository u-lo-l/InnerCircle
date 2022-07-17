/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:19:34 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 21:19:25 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	_x = Fixed();
	_y = Fixed();
}

Point::Point(float a, float b)
{
	_x = Fixed(a);
	_y = Fixed(b);
}

Point::~Point() {}

Fixed Point::getX( void ) const
{
	Fixed temp;

	temp.setRawBits(_x.getRawBits());
	return (temp);
}

Fixed Point::getY( void ) const
{
	Fixed temp;

	temp.setRawBits(_y.getRawBits());
	return (temp);
}

Point::Point(const Point & p)
{
	this->_x.setRawBits(p.getX().getRawBits());
	this->_y.setRawBits(p.getY().getRawBits());
}


Point & Point::operator=(const Point & p)
{
	if (this == &p)
		return (*this);
	this->_x.setRawBits(p.getX().getRawBits());
	this->_y.setRawBits(p.getY().getRawBits());
	return (*this);
}

Point Point::operator-(const Point &fp) const
{
	Point	res;
	float	x, y;

	x = this->_x.toFloat() - fp.getX().toFloat();
	y = this->_y.toFloat() - fp.getY().toFloat();
	res = Point(x, y);
	return (res);
}

bool Point::operator!=(const Point & p)
{
	return ((this->getX() != p.getX()) && (this->getY() != p.getY()));
}

bool Point::operator==(const Point & p)
{
	return ((this->getX() == p.getX()) && (this->getY() == p.getY()));
}

std::ostream & operator<<(std::ostream & os, Point const & p)
{
	os << "(" << p.getX() << " , " << p.getY() << ")";
	return (os);
}
