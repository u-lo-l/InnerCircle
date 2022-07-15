/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_more_sed.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:22:53 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 19:27:22 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "no_more_sed.hpp"
#include <iostream>
#include <cstdlib>
#include <istream>
#include <fstream>

void exit_err(const std::string str)
{
	std::cout << str << std::endl;
	exit (1);
}

bool read_from_file(const std::string & filename, std::string & temp)
{
	std::ifstream inFile;
	
	inFile.open(filename.c_str());
	if (inFile.is_open() == false)
		exit_err("Fail to open " + filename);
	temp = "";
	std::string line;
	while (true)
	{
		std::getline(inFile, line);
		if (inFile.eof() == true)
		{
			temp += line;
			break;
		}
		if (inFile.fail() == true)
		{
			std::cerr << "Failed to read file\n";
			inFile.close();
			return (false) ;
		}
		temp += (line + '\n');
	}
	inFile.close();
	return (true);
}

void ft_replace(std::string & source, const std::string & s1, const std::string &s2)
{
	const size_t s1_len = s1.length();
	size_t	start = 0;
	
	while ((start = source.find(s1, start)) != std::string::npos)
		source.erase(start, s1_len).insert(start, s2);
}
