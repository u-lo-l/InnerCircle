/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:27:19 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 19:27:16 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "no_more_sed.hpp"
#include <iostream>
#include <istream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		exit_err("USAGE : no_more_sed <filename> <string1> <string2>");
	std::string filename(argv[1]);
	std::string string1(argv[2]);
	std::string string2(argv[3]);

	std::string temp;
	if (read_from_file(filename, temp) == false)
		return (1);

	std::ofstream outFile;
	outFile.open((filename + ".replace").c_str());
	if (outFile.is_open() == false)
		exit_err("Fail to make .replace file");
	ft_replace(temp, string1, string2);
	outFile << temp;
	outFile.close();
	return (0);
}
