/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:35:37 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 01:31:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat : Default constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat : Default destructor called\n";
}

Cat::Cat( const Cat & C ) : Animal(C)
{
	std::cout << "Cat : Copy constructor called\n";
}

Cat & Cat::operator=(const Cat & D)
{
	std::cout << "Cat : Assignment operator called\n";
	this->_type = D.getType();
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat : miaooo\n";
}