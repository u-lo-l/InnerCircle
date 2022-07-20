/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:36:09 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 19:37:32 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printData.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Just One argument is requried\n";
		return (1);
	}

	std::string literal = static_cast<std::string>(argv[1]);
	void (* converser[4])( const std::string &) = {
		printChar, printInt, printFloat, printDouble
	};
	
	for (int i = 0 ; i < 4 ; i++)
	{
		try		{ converser[i](literal);}
		catch(const std::out_of_range & e)	{ std::cerr << e.what() << '\n'; }
		catch(const std::invalid_argument & e)	{ std::cerr << e.what() << '\n'; }
	}
	return (0);
}
