/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:49:30 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 18:49:38 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span( void )
:_size(0), _capacity(0), _arr(std::vector<int>(0))
{
    //do nothing more
}

Span::Span( unsigned int N )
:_size(0), _capacity(N), _arr(std::vector<int>(N))
{
    //do nothing more
}

Span::~Span()
{
    //do nothing
}

Span::Span( const Span & s)
:_size(s._size), _capacity(s._capacity), _arr(s._capacity)
{
    this->_arr.assign(s._arr.begin(), s._arr.end());
}

Span & Span::operator=( const Span & s)
{
    if (this == &s)
        return (*this);
    this->_arr.assign(s._arr.begin(), s._arr.end());
    return (*this);
}

const char * Span::tooManyElements::what() const throw()
{
    return ("Excepction : too many elems");
}

const char * Span::notEnoughElemnts::what() const throw()
{
    return ("Excepction : not enoungh elems");
}

void Span::addNumber( const int & a )
{
    if (_size >= _capacity)
        throw (tooManyElements());
    _arr.push_back(a);
    _size++;
}

unsigned int Span::shortestSpan( void ) const
{
    unsigned int span = std::numeric_limits<unsigned int>::max();
    int   tmp1, tmp2;
    if (_size <= 1)
        throw (notEnoughElemnts());
    for (std::vector<int>::iterator iter = _arr.begin() ; iter + 1 != _arr.end() ; iter++)
    {
        tmp1 = *iter;
        tmp2 = *(iter + 1);
        span = std::min(span, static_cast<unsigned int>(std::abs(tmp1 - tmp2)));
    }
    return (span);
}
unsigned int Span::longestSpan( void ) const
{
    unsigned int span = std::numeric_limits<unsigned int>::min();
    int   tmp1, tmp2;
    if (_size <= 1)
        throw (notEnoughElemnts());
    for (std::vector<int>::iterator iter = _arr.begin() ; iter + 1 != _arr.end() ; iter++)
    {
        tmp1 = *iter;
        tmp2 = *(iter + 1);
        span = std::max(span, static_cast<unsigned int>(std::abs(tmp1 - tmp2)));
    }
    return (span);
}

unsigned int Span::getSize( void ) const
{
    return (_size);
}

unsigned int Span::getCapacity( void ) const
{
    return (_capacity);
}