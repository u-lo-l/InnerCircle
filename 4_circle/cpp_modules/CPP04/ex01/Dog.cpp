/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:35:28 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 16:52:50 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog : Default constructor called\n";
	_pbrain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog : Default destructor called\n";
	delete _pbrain;
}

Dog::Dog( const Dog & D ) : Animal("Dog")
{
	std::cout << "Dog : Copy constructor called\n";
	_pbrain = new Brain;
	(*_pbrain) = (*D._pbrain);
}

Dog & Dog::operator=(const Dog & D)
{
	std::cout << "Dog : Assignment operator called\n";
	if (this == &D)
		return (*this);
	this->_type = D._type;
	delete this->_pbrain;
	this->_pbrain = new Brain();
	(*_pbrain) = (*D._pbrain);
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog : bowwow\n";
}

void Dog::addIdea(const std::string & idea ) const
{
	_pbrain->addIdea(idea);
}

std::string Dog::getIdea( unsigned int i ) const
{
	return (_pbrain->getIdea(i));
}