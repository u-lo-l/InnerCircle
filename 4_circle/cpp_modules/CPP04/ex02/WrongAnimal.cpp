/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:09:04 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 15:19:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string & animaltype)
: _type(animaltype)
{
	std::cout << "WrongAnimal : Default constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : Default destructor called\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal & A )
{
	std::cout << "WrongAnimal : Copy constructor called\n";
	this->_type = A.getType();
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & A )
{
	std::cout << "WrongAnimal : Assignment operator called\n";
	this->_type = A.getType();
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal : ??????????\n";
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}
