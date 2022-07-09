/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:35:37 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 04:48:32 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat : Default constructor called\n";
}

Cat::~Cat()
{
	delete	_brain;
	std::cout << "Cat : Default destructor called\n";
}

Cat::Cat( const Cat & C ) : Animal()
{
	std::cout << "Cat : Copy constructor called\n";
	_brain = new Brain(*(C.getBrain()));
	this->_type = C.getType();
}

Cat & Cat::operator=(const Cat & C)
{
	std::cout << "Cat : Assignment operator called\n";
	if (this == &C)
		return (*this);
	this->_type = C.getType();
	delete _brain;
	_brain = new Brain(*(C.getBrain()));
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat : miaooo\n";
}

Brain * Cat::getBrain( void ) const
{
	return (_brain);
}
