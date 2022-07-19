/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:23:42 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 15:22:44 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal(const std::string & animaltype)
: _type(animaltype)
{
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
	std::cout << "Animal : ...\n";
}

std::string Animal::getType() const
{
	return (this->_type);
}
