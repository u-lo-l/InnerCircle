/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 18:09:28 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
private :
	int	_value;
	const static int _FRACBITS;
public :
	Fixed( void );
	Fixed(const Fixed & fp);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed( void );

	Fixed & operator=(const Fixed  & fp);

	bool operator>(const Fixed  & fp) const;
	bool operator<(const Fixed  & fp) const;
	bool operator>=(const Fixed  & fp) const;
	bool operator<=(const Fixed  & fp) const;
	bool operator==(const Fixed  & fp) const;
	bool operator!=(const Fixed  & fp) const;

	Fixed operator+(const Fixed &fp) const;
	Fixed operator-(const Fixed &fp) const;
	Fixed operator*(const Fixed &fp) const;
	Fixed operator/(const Fixed &fp) const;

	Fixed & operator++( void );
	Fixed operator++(int);
	Fixed & operator--( void );
	Fixed operator--(int);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed min(Fixed & f1, Fixed & f2);
	const static Fixed min(const Fixed & f1, const Fixed & f2);
	static Fixed max(Fixed & f1, Fixed & f2);
	const static Fixed max(const Fixed & f1, const Fixed & f2);
};

std::ostream & operator<<(std::ostream & os, const Fixed & c);

#endif
