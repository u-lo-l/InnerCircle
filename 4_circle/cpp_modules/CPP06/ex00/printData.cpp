/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:02:37 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 18:44:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printData.hpp"
#include <limits>

void printChar( const std::string & literal )
{
	int		temp;
	char	c;

	std::cout << "char: ";
	if (literal.length() == 1 && isdigit(literal[0]) == false)
		temp = static_cast<int>(literal[0]);
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		temp = static_cast<int>(literal[1]);
	else
		temp = ft_stoi(literal);
	if (temp < 0 || temp > std::numeric_limits<char>::max())
		throw (std::out_of_range("impossible"));
	else
		c = static_cast<char>(temp);
	if (isprint(c) == false)
		throw (std::invalid_argument("Non displayable"));
	else 
		std::cout << "'" << c << "'\n";
}

void printInt( const std::string & literal )
{
	int	i;

	std::cout << "int: ";
	if (literal.length() == 1 && isdigit(literal[0]) == false)
		i = static_cast<int>(literal[0]);
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		i = static_cast<int>(literal[1]);
	else
		i = ft_stoi(literal);
	std::cout << i << std::endl;
	
}

void printFloat( const std::string & literal )
{
	float f;

	std::cout << "float: ";
	if (literal.length() == 1 && isdigit(literal[0]) == false)
		f = static_cast<float>(literal[0]);
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		f = static_cast<float>(literal[1]);
	else
		f = ft_stof(literal);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	std::cout << f << "f\n";
}

void printDouble( const std::string & literal )
{
	double d;

	std::cout << "double: ";
	if (literal.length() == 1 && isdigit(literal[0]) == false)
		d = static_cast<double>(literal[0]);
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		d = static_cast<double>(literal[1]);
	else
		d = ft_stod(literal);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	std::cout << d << std::endl;
}