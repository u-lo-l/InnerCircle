/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:57:21 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 02:52:46 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure( void ) : AMateria("cure")
{
	std::cout << "\033[38;5;226m";
	std::cout << "Cure : Default Constructor called\n";
	std::cout << "\033[0m";
}

Cure::Cure( const Cure & C ) : AMateria("cure")
{
	_name = C.getType();
	std::cout << "\033[38;5;226m";
	std::cout << "Cure : Copy Constructor called\n";
	std::cout << "\033[0m";
}

Cure::~Cure( void )
{
	std::cout << "\033[38;5;226m";
	std::cout << "Cure : Default Destructor called\n";
	std::cout << "\033[0m";
}

Cure	& Cure::operator=( const Cure & other )
{
	this->_name = other.getType();
	return (*this);
}

AMateria * Cure::clone( void ) const
{
	std::cout << "    Cure : cloning cure\n";
	AMateria * mat =new Cure(*this);

	return (mat);
}

void Cure::use(ICharacter & target)
{
	std::cout << "\033[38;5;226m";
	std::cout << "* heals " << target.getType() << "'s wounds *\n";
	std::cout << "\033[0m";
}