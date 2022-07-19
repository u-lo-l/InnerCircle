/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:35:28 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 15:18:11 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog : Default constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog : Default destructor called\n";
}

Dog::Dog( const Dog & D ) : Animal(D)
{
	std::cout << "Dog : Copy constructor called\n";
}

Dog & Dog::operator=(const Dog & D)
{
	std::cout << "Dog : Assignment operator called\n";
	this->_type = D.getType();
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog : bowwow\n";
}