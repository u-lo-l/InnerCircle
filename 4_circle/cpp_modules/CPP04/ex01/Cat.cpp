/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:35:37 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 12:06:44 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat : Default constructor called\n";
	_pbrain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat : Default destructor called\n";
	delete _pbrain;
}

Cat::Cat( const Cat & C ) : Animal(C)
{
	std::cout << "Cat : Copy constructor called\n";
	_pbrain = new Brain;
	(*_pbrain) = (*C._pbrain);
}

Cat & Cat::operator=(const Cat & C)
{
	std::cout << "Cat : Assignment operator called\n";
	if (this == &C)
		return (*this);
	this->_type = C._type;
	delete this->_pbrain;
	this->_pbrain = new Brain();
	(*_pbrain) = (*C._pbrain);
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat : Meow\n";
}

void Cat::addIdea(const std::string & idea ) const
{
	_pbrain->addIdea(idea);
}

std::string Cat::getIdea( unsigned int i ) const
{
	return (_pbrain->getIdea(i));
}