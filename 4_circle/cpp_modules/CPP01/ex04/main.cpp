/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:27:19 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/28 14:00:55 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <istream>

void exit_err(std::string str);

void ft_replace(std::string & source, const std::string & s1, const std::string &s2);

int main(int argc, char **argv)
{
	if (argc != 4)
		exit_err("USAGE : no_more_sed <filename> <string1> <string2>");
	std::string filename(argv[1]);
	std::string string1(argv[2]);
	std::string string2(argv[3]);

	std::ifstream inFile;
	std::ofstream outFile;

	inFile.open(filename);
	if (inFile.is_open() == false)
		exit_err("Fail to open " + filename);
	outFile.open(filename + ".replace");
	if (outFile.is_open() == false)
	{
		inFile.close();
		exit_err("Fail to make replace file");
	}
	std::string temp("");
	std::string line;
	while (true)
	{
		std::getline(inFile, line);
		if (inFile.fail() == true)
		{
			std::cout << "infile failed\n";
			std::cout << "curr teemp : " << temp;
			// break ;
		}
		temp += line;
		if (inFile.eof() == false)
			temp += "\n";
		else
		{
			std::cout << "met EOF\n";
			break;
		}
	}
	inFile.close();
	ft_replace(temp, string1, string2);
	outFile << temp;
	outFile.close();
}

void exit_err(std::string str)
{
	std::cout << str << std::endl;
	exit (1);
}

void ft_replace(std::string & source, const std::string & s1, const std::string &s2)
{
	const size_t s1_len = s1.length();
	size_t	start = 0;
	while ((start = source.find(s1, start)) != std::string::npos)
		source.erase(start, s1_len).insert(start, s2);
}