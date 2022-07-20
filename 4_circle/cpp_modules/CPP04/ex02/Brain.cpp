/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:30:32 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 16:45:43 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() : _numOfIdeas(0)
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
	_numOfIdeas = B.getIndex();
	for (unsigned int i = 0 ; i < _numOfIdeas ; i++)
		_ideas[i] = B.getIdea(i);
}

Brain & Brain::operator=( const Brain & B )
{
	std::cout << "Brain assign operator called\n";
	if (this == &B)
		return (*this);
	_numOfIdeas = B.getIndex();
	for (unsigned int i = 0 ; i < _numOfIdeas ; i++)
		_ideas[i] = B.getIdea(i);
	return (*this);
}

int			Brain::getIndex() const
{
	return (_numOfIdeas);
}

std::string Brain::getIdea( unsigned int i ) const
{
	if (i >= _numOfIdeas )
	{
		std::cerr << "Brain : getIdea fail. invalid index";
		return ("");
	}
	return (_ideas[i]);
}

void Brain::addIdea( std::string str )
{
	if (_numOfIdeas > 99)
	{
		std::cout << "Brain : setIdea fail. ideas are full\n";
		return;
	}
	_ideas[_numOfIdeas++] = str;
}