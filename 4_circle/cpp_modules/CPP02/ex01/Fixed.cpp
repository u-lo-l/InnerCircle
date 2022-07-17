/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 17:23:23 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_FRACBITS = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(const Fixed & fp)
{
	std::cout << "Copy constructor called\n";
	*this = fp;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << Fixed::_FRACBITS;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << Fixed::_FRACBITS));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructure called\n";
}

Fixed & Fixed::operator=(Fixed const & fp)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &fp)
		return (*this);
	this->_value = fp.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called\n";
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_value) / float(1 << Fixed::_FRACBITS));
}

int Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_FRACBITS);
}

std::ostream & operator<<(std::ostream & os, const Fixed & fp)
{
	os << fp.toFloat();
	return (os);
}
