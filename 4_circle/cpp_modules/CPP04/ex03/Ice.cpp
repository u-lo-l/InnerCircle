/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:35:12 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 02:52:49 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

const std::string _message = "shoots an ice bolt at";

Ice::Ice( void ) : AMateria("ice")
{
	std::cout << "\033[38;5;81m";
	std::cout << "Ice : Default Constructor called\n";
	std::cout << "\033[0m";
}

Ice::Ice( const Ice & I ) : AMateria("ice")
{
	_name = I.getType();
	std::cout << "\033[38;5;81m";
	std::cout << "Ice : Copy Constructor called\n";
	std::cout << "\033[0m";
}

Ice::~Ice( void )
{
	std::cout << "\033[38;5;81m";
	std::cout << "Ice : Default Destructor called\n";
	std::cout << "\033[0m";
}

Ice	& Ice::operator=( const Ice & other )
{
	this->_name = other.getType();
	return (*this);
}

AMateria * Ice::clone( void ) const
{
	std::cout << "    Ice : cloning ice\n";
	AMateria * mat = new Ice(*this);

	return (mat);
}

void Ice::use(ICharacter & target)
{
	std::cout << "\033[38;5;81m";
	std::cout << "* shoots an ice bolt at " << target.getType() << " *\n";
	std::cout << "\033[0m";
}