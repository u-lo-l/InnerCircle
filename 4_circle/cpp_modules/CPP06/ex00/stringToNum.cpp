/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringToNum.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:05:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 19:38:18 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringToNum.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>

static std::string case_floatinput(const std::string & s)
{
	std::string str(s);
	if (s.size() > 1 && s[s.size() - 1] == 'f')
	{
		str[s.size() - 1] = 0;
		str.resize(s.size() - 1);
		std::cout << "[" << str << "]" << std::endl;
	}
	return (str);
}

int ft_stoi( const std::string & s )
{
	std::string str = case_floatinput(s);
	double tempD;
	long i;
	int min, max;
	std::istringstream iss(str);

	min = std::numeric_limits<int>::min();
	max = std::numeric_limits<int>::max();
	
	iss >> tempD;
	
	i = static_cast<long>(tempD);
	if (iss.fail() == true || iss.eof() == false)
		throw (std::invalid_argument("impossible"));
	else if (i < min || i > max)
		throw (std::out_of_range("impossible"));
	else
		return (static_cast<int>(i));
}

double ft_stod( const std::string & s )
{
	std::string str = case_floatinput(s);
	double d;
	std::istringstream iss(str);

	if (str == "nanf" || str == "nan")
		return (nan(""));
	else if (str == "inff" || str == "inf")
		return (std::numeric_limits<double>::infinity());
	else if (str == "-inff" || str == "-inf")
		return (-std::numeric_limits<double>::infinity());
	iss >> d;
	if (iss.fail() == true || iss.eof() == false)
		throw (std::invalid_argument("impossible"));
	return (d);
}
