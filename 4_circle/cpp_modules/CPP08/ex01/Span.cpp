/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:49:30 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/24 19:52:36 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <limits>
#include <cstdlib> // for abs


Span::Span( unsigned int N ) :_capacity(N), _size(0) { }

Span::~Span() { }

Span::Span( const Span & s) :_capacity(s._capacity), _size(s._size)
{
	this->_arr = s._arr;
}

Span & Span::operator=( const Span & s)
{
	if (this == &s)
		return (*this);
	this->_arr = s._arr;
	return (*this);
}

const char * Span::tooManyElements::what() const throw()
{
	return ("\033[3;31mExcepction : too many elems\033[0m");
}

const char * Span::notEnoughElemnts::what() const throw()
{
	return ("\033[3;31mExcepction : not enoungh elems\033[0m");
}

void Span::addNumber( int a )
{
	if (_size >= _capacity)
		throw (tooManyElements());
	std::cout << "\033[1;33mA number added : ";
	std::cout << a << "\033[0m" << std::endl;
	_arr.push_back(a);
	_size++;
}

unsigned int Span::shortestSpan( void ) const
{
	if (_size <= 1)
		throw (notEnoughElemnts());
	std::vector<int> temp(_arr.size());
	unsigned int span = std::numeric_limits<unsigned int>::max();
	std::copy(this->_arr.begin(), this->_arr.end(), temp.begin());
	std::sort(temp.begin(), temp.end());
	std::vector<int>::iterator it = temp.begin();
	while ( it != temp.end() )
	{
		int one = *it;
		int two = *++it;
		span = std::min(span, static_cast<unsigned int>(two - one));
	}
	return (span);
}
unsigned int Span::longestSpan( void ) const
{
	if (_size <= 1)
		throw (notEnoughElemnts());
	std::vector<int> temp(_arr.size());
	std::copy(this->_arr.begin(), this->_arr.end(), temp.begin());
	std::sort(temp.begin(), temp.end());
	return (static_cast<unsigned int>(temp.back() - temp.front()));
}

unsigned int Span::getSize( void ) const
{
	return (_size);
}

unsigned int Span::getCapacity( void ) const
{
	return (_capacity);
}
