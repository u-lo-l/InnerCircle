/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:23:42 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 01:31:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	_type = "";
	std::cout << "Animal : Default constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal : Default destructor called\n";
}

Animal::Animal( const Animal & A )
{
	std::cout << "Animal : Copy constructor called\n";
	this->_type = A.getType();
}

Animal & Animal::operator=( Animal const & A )
{
	std::cout << "Animal : Assignment operator called\n";
	this->_type = A.getType();
	return (*this);
}

void Animal::makeSound( void ) const
{
	std::cout << "Animal : ??????????\n";
}

std::string Animal::getType() const
{
	return (this->_type);
}
