/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:59:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/25 12:13:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template<typename T>
class Array
{
private :
	unsigned int _size;
	T * _array;
public :
	Array();
	Array( unsigned int n );
	Array( const Array & A );
	~Array();
	Array & operator=( const Array & A );
	T & operator[]( unsigned int index ) const ;
	T & operator[]( unsigned int index ) ;
	unsigned int size( void ) const;
};

template<typename T>
Array<T>::Array() : _size(0)
{
	this->_array = new T[_size];
}

template<typename T>
Array<T>::Array(unsigned int n ) : _size(n)
{
	this->_array = new T[_size];
}

template<typename T>
Array<T>::Array( const Array & A ) : _size(A._size)
{
	this->_array = new T[_size];
	for (unsigned int i = 0 ; i < _size ; i++)
		this->_array[i] = A._array[i];
}

template<typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template<typename T>
Array<T> & Array<T>::operator=( const Array & A )
{
	if (this == &A)
		return (*this);
	delete [] _array;
	this->_size = A._size;
	this->_array = new T[_size];
	for (int i = 0 ; i < _size ; i++)
		this->_array[i] = A[i];
	return (*this);
}

template<typename T>
T & Array<T>::operator[]( unsigned int index ) const
{
	std::cout << "\033[2mconst [] called\n\033[0m";
	if ( index >= _size )
		throw (std::out_of_range("\033[3;31mindex out of range\033[0m"));
	return (_array[index]);
}

template<typename T>
T & Array<T>::operator[]( unsigned int index )
{
	std::cout << "\033[2mnon_const [] called\n\033[0m";
	if ( index >= _size )
		throw (std::out_of_range("\033[3;31mindex out of range\033[0m"));
	return (_array[index]);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif
