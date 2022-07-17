/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 15:55:03 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
private :
	const static int _FRACBITS;
	int	_value;
public :
	Fixed( void );
	Fixed(const Fixed & fp);
	~Fixed( void );

	Fixed & operator=( const Fixed & fp );

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
