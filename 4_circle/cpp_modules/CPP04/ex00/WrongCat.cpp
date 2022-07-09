/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:35:37 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 01:32:22 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat : Default constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : Default destructor called\n";
}

WrongCat::WrongCat( const WrongCat & C ) : WrongAnimal(C)
{
	std::cout << "WrongCat : Copy constructor called\n";
}

WrongCat & WrongCat::operator=(const WrongCat & D)
{
	std::cout << "WrongCat : Assignment operator called\n";
	this->_type = D.getType();
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat : Grrrr\n";
}