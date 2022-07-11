/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringToNum.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:05:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/12 03:41:01 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringToNum.hpp"
# include <limits>
# include <cmath>
# include <sstream>

int ft_stoi( const std::string & s )
	throw(std::out_of_range &, std::invalid_argument &)
{
	long i;
	int min, max;
	std::istringstream iss(s);

	min = std::numeric_limits<int>::min();
	max = std::numeric_limits<int>::max();
	
	iss >> i;
	
	if (iss.fail() == true)
		throw (std::invalid_argument("impossible"));
	else if (i < min || i > max)
		throw (std::out_of_range("impossible"));
	else
		return (static_cast<int>(i));
}

float ft_stof( const std::string & s )
	throw(std::out_of_range &, std::invalid_argument &)
{
	float f;
	std::istringstream iss(s);

	if (s == "nanf" || s == "nan")
		return (nanf(""));
	else if (s == "inff" || s == "inf")
		return (std::numeric_limits<float>::infinity());
	else if (s == "-inff" || s == "-inf")
		return (-std::numeric_limits<float>::infinity());
	iss >> f;
	if (iss.bad() == true)
	{
		std::cerr << "bad\n";
	}
	if (iss.fail() == true)
	{
		throw (std::invalid_argument("impossible"));
	}
	// else if () // overflow or underflow
	// {
		
	// }
	else
		return (f);
}

double ft_stod( const std::string & s )
	throw(std::out_of_range &, std::invalid_argument &)
{
	double d;
	std::istringstream iss(s);

	if (s == "nanf" || s == "nan")
		return (nan(""));
	else if (s == "inff" || s == "inf")
		return (std::numeric_limits<double>::infinity());
	else if (s == "-inff" || s == "-inf")
		return (-std::numeric_limits<double>::infinity());
	iss >> d;
	if (iss.fail() == true)
		throw (std::invalid_argument("impossible"));
	return (d);
}
