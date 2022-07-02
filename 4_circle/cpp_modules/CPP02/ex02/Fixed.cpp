/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 18:16:55 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bits = 8;

Fixed Fixed::min(Fixed & f1, Fixed & f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}
const Fixed Fixed::min(const Fixed & f1, const Fixed & f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}
Fixed Fixed::max(Fixed & f1, Fixed & f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}
const Fixed Fixed::max(const Fixed & f1, const Fixed & f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}

Fixed::Fixed( void )
{ _value = 0; }

Fixed::Fixed(const Fixed & fp)
{ *this = fp; }

Fixed::Fixed(const int n)
{ this->_value = n << Fixed::_bits; }

Fixed::Fixed(const float f)
{ this->_value = roundf(f * (1 << Fixed::_bits)); }

Fixed::~Fixed( void ){ }

Fixed & Fixed::operator=(Fixed const & fp)
{
	if (this == &fp)
		return (*this);
	this->_value = fp.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed  & fp) const
{
	return (_value > fp.getRawBits());
}
bool Fixed::operator<(const Fixed  & fp) const
{
	return (_value < fp.getRawBits());
}
bool Fixed::operator>=(const Fixed  & fp) const
{
	return (_value >= fp.getRawBits());
}
bool Fixed::operator<=(const Fixed  & fp) const
{
	return (_value <= fp.getRawBits());
}
bool Fixed::operator==(const Fixed  & fp) const
{
	return (_value == fp.getRawBits());
}
bool Fixed::operator!=(const Fixed  & fp) const
{
	return (_value != fp.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fp) const
{
	Fixed	val = Fixed(*this);

	val.setRawBits(this->_value + fp.getRawBits());
	return (val);
}
Fixed Fixed::operator-(const Fixed &fp) const
{
	Fixed	val = Fixed(*this);

	val.setRawBits(this->_value - fp.getRawBits());
	return (val);
}
Fixed Fixed::operator*(const Fixed &fp) const
{
	Fixed	val = Fixed(*this);
	long	temp[2] = {long(_value), long(fp.getRawBits())};

	val.setRawBits((temp[0] * temp[1]) >> Fixed::_bits);
	return (val);
}
Fixed Fixed::operator/(const Fixed &fp) const
{
	Fixed	val = Fixed(*this);
	long	temp[2] = {long(_value), long(fp.getRawBits())};

	val.setRawBits((temp[0] << Fixed::_bits) / temp[1]);
	return (val);
}

Fixed & Fixed::operator++( void )
{
	_value++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed F(*this);

	_value++;
	return (F);
}
Fixed & Fixed::operator--( void )
{
	_value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed F(*this);
	
	_value--;
	return (F);
}

int Fixed::getRawBits( void ) const
{ return (this->_value); }

void Fixed::setRawBits( int const raw )
{ this->_value = raw; }

float Fixed::toFloat(void) const
{ return ((float)(this->_value) / float(1 << Fixed::_bits)); }

int Fixed::toInt(void) const
{ return (this->_value >> Fixed::_bits); }

std::ostream & operator<<(std::ostream & os, const Fixed & fp)
{
	os << fp.toFloat();
	return (os);
}