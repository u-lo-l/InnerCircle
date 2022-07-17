/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:17 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/02 21:26:47 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool setTriangle(Point (& tri)[3]);
bool checkTriangle(Point (& tri)[3]);
bool setPoint(Point & p);

int	main( void )
{
	Point tri[3], p;

	std::cout << "BSP : Ctrl + C to Quit\n";
	std::cout << "\033[3;31m";
	std::cout << "unexpected input may occur error. \033[1mjust use number\n";
	std::cout << "\033[0m";
	if ( setTriangle(tri) == false)
		return (1);
	std::cout << "triangle info\n";
	std::cout << tri[0] << " " << tri[1] << " " << tri[2] << std::endl;
	while (true)
	{
		if ( setPoint(p) == false)
			return (1);
		if (bsp(tri[0], tri[1], tri[2], p) == true)
			std::cout << "inside\n";
		else
			std::cout << "outside\n";
	}
}

bool setTriangle(Point (& tri)[3])
{
	std::cout << "Set 3 vertices of triangle\n";
	for (int i = 0 ; i < 3 ; i++)
	{
		float f1, f2;
		std::cout << "vertex " << i << "\n";
		std::cout << "\tx_cord : ";
		std::cin >> f1;
		if (std::cin.fail() == true)
		{
			std::cout << "ERROR : input fail Quit Program\n";
			return (false);
		}
		std::cout << "\ty_cord : ";
		std::cin >> f2;
		if (std::cin.fail() == true)
		{
			std::cout << "ERROR : input fail Quit Program\n";
			return (false);
		}
		tri[i] = Point(f1, f2);
	}
	if (checkTriangle(tri) == false)
		return (false);
	return (true);
}

bool checkTriangle(Point (& tri)[3])
{
	if (tri[0] == tri[1] || tri[0] == tri[2] || tri[1] == tri[2])
	{
		std::cout << "ERROR : triangle error Quit Program\n";
		return (false);
	}
	Fixed x[2], y[2];
	
	x[0] = (tri[0].getX() - tri[1].getX()).toFloat();
	y[0] = (tri[0].getY() - tri[1].getY()).toFloat();

	x[1] = (tri[1].getX() - tri[2].getX()).toFloat();
	y[1] = (tri[1].getY() - tri[2].getY()).toFloat();
	if (x[0] * y[1] == x[1] * y[0])
	{
		std::cout << "ERROR : triangle error Quit Program\n";
		return (false);
	}
	return (true);
}


bool setPoint(Point & p)
{
	float f1, f2;
	
	std::cout << "BSP : choose a point\n";
	std::cout << "\tx_cord : ";
	std::cin >> f1;
	if (std::cin.fail() == true)
	{
		std::cout << "ERROR : input fail Quit Program\n";
		return (false);
	}
	std::cout << "\ty_cord : ";
	std::cin >> f2;
	if (std::cin.fail() == true)
	{
		std::cout << "ERROR : input fail Quit Program\n";
		return (false);
	}
	p = Point(f1, f2);
	return (true);
}
