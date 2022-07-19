/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:17 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 14:28:53 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main( void )
{
	{
		std::cout << "subject test case" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	Fixed a, b;
	a = 42.42f;
	b = 24.2f;
	{
		std::cout << "Four arithmetic operation" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "Addition" << std::endl;
		std::cout << "a + b = " << a + b << std::endl;
		std::cout << "Subtraction" << std::endl;
		std::cout << "a - b = " << a - b << std::endl;
		std::cout << "Mutiplication" << std::endl;
		std::cout << "a * b = " << a * b << std::endl;
		std::cout << "Division" << std::endl;
		std::cout << "a / b = " << a / b << std::endl;
	}
	{
		std::cout << "Logical operation" << std::endl;
		std::cout << a << " and " << b << std::endl;
		std::cout << "a > b  : " << ((a > b) ? "TRUE" : "FALSE" ) << std::endl;
		std::cout << "a < b  : " << ((a < b) ? "TRUE" : "FALSE" ) << std::endl;
		std::cout << "a >= b : " << ((a >= b) ? "TRUE" : "FALSE" ) << std::endl;
		std::cout << "a <= b : " << ((a <= b) ? "TRUE" : "FALSE" ) << std::endl;
		std::cout << "a == b : " << ((a == b) ? "TRUE" : "FALSE" ) << std::endl;
		std::cout << "a != b : " << ((a != b) ? "TRUE" : "FALSE" ) << std::endl;
	}
}