/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:35:37 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 15:19:05 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
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
	std::cout << "Cat : Meow\n";
}