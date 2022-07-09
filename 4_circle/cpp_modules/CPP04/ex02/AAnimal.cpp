/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:23:42 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 06:21:24 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	_type = "";
	std::cout << "AAnimal : Default constructor called\n";
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal : Default destructor called\n";
}

AAnimal::AAnimal( const AAnimal & A )
{
	std::cout << "AAnimal : Copy constructor called\n";
	this->_type = A.getType();
}

AAnimal & AAnimal::operator=( AAnimal const & A )
{
	std::cout << "AAnimal : Assignment operator called\n";
	this->_type = A.getType();
	return (*this);
}

std::string AAnimal::getType() const
{
	return (this->_type);
}
