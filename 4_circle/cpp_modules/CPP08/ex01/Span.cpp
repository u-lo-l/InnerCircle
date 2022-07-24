/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:49:30 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/23 16:33:05 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
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
	_arr.insert(a);
	_size++;
}

unsigned int Span::shortestSpan( void ) const
{
	if (_size <= 1)
		throw (notEnoughElemnts());
	std::multiset<int>::iterator it = _arr.begin();
	int min1 = *it;
	int min2 = *(++it);
	return (static_cast<unsigned int>(min2 - min1));
}
unsigned int Span::longestSpan( void ) const
{
	if (_size <= 1)
		throw (notEnoughElemnts());
	int min = *_arr.begin();
	int max = *_arr.rbegin();
	return (static_cast<unsigned int>(max - min));
}
void Span::showInfo( void ) const
{
	std::cout << "\033[1;3;34m";
	std::cout << "  Span Object Info" << std::endl;
	std::cout << "\033[0;3;34m";
	std::cout << "  Whole capacity : " << _capacity << std::endl;
	std::cout << "  Current size   : " << _size << std::endl;
	if (_size > 1)
	{
		std::multiset<int>::iterator it = _arr.begin();
		std::cout << "  min1 : " << *(it++) << std::endl;
		std::cout << "  min2 : " << *(it) << std::endl;
		std::cout << "  max : " << *(_arr.rbegin()) << std::endl;
		std::cout << "  Spans : " << shortestSpan() << ", " << longestSpan() << std::endl;
	}
	std::cout << "\033[0m";
}

unsigned int Span::getSize( void ) const
{
	return (_size);
}

unsigned int Span::getCapacity( void ) const
{
	return (_capacity);
}
