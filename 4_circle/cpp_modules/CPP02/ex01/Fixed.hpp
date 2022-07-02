/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 16:18:29 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
private :
	int	_value;
	const static int _bits;
public :
	Fixed( void );
	Fixed(const Fixed & fp);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed( void );

	Fixed & operator=(Fixed const & fp);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & os, const Fixed & c);

#endif