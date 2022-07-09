/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:09:04 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 01:32:27 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "";
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
