/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:30:32 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 05:02:04 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() : _index(-1)
{
	std::cout << "Brain : Default constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain : Default destructor called\n";
}

Brain::Brain( const Brain & B )
{
	std::cout << "Brain : copy constructor called\n";
	_index = B.getIndex();
	for (int i = 0 ; i <= _index ; i++)
		_ideas[i] = B.getIdea(i);
}

Brain & Brain::operator=( const Brain & B )
{
	_index = B.getIndex();
	for (int i = 0 ; i <= _index ; i++)
		_ideas[i] = B.getIdea(i);
	return (*this);
}

int			Brain::getIndex() const
{
	return (_index);
}

std::string Brain::getIdea( int i ) const
{
	if (i > _index || i < 0)
	{
		std::cout << "Brain : getIdea fail. invalid index";
		return ("");
	}
	return (_ideas[i]);
}

void Brain::setIdea( std::string str )
{
	if (_index >= 99)
	{
		std::cout << "Brain : setIdea fail. ideas are full\n";
		return;
	}
	_ideas[++_index] = str;
}