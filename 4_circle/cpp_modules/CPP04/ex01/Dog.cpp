/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:35:28 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 04:54:04 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog : Default constructor called\n";
}

Dog::~Dog()
{
	delete	this->_brain;
	std::cout << "Dog : Default destructor called\n";
}

Dog::Dog( const Dog & D ) : Animal()
{
	std::cout << "Dog : Copy constructor called\n";
	this->_brain = new Brain(*(D.getBrain()));
	this->_type = D.getType();
}

Dog & Dog::operator=(const Dog & D)
{
	std::cout << "\033[3;31mDog : Assignment operator called\033[0m\n";
	if (this == &D)
		return (*this);
	delete this->_brain;
	this->_brain = new Brain(*(D.getBrain()));
	this->_type = D.getType();
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog : miaooo\n";
}

Brain * Dog::getBrain( void ) const
{
	return (this->_brain);
}
