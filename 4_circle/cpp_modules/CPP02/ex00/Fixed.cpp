/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 15:59:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::_FRACBITS = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(const Fixed & fp)
{
	std::cout << "Copy constructor called\n";
	_value = fp.getRawBits();
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
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
}
