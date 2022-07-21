/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:09:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 15:26:52 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main ()
{
	const std::string TYPES[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
	};
	srand(time(NULL));
	{
		std::cout << "================CASE 1(Shrubbery)================" << std::endl;
		try
		{
			Intern someRandomIntern;
			Form * S = someRandomIntern.makeForm(TYPES[0], "Bberry");
			std::cout << S->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "================CASE 2(Robotomy)================" << std::endl;
		try
		{
			Intern someRandomIntern;
			Form * S = someRandomIntern.makeForm(TYPES[1], "Blender");
			std::cout << S->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "================CASE 3(Persidential)================" << std::endl;
		try
		{
			Intern someRandomIntern;
			Form * S = someRandomIntern.makeForm(TYPES[2], "Plender");
			std::cout << S->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "================CASE 4(fail)================" << std::endl;
		try
		{
			Intern someRandomIntern;
			Form * S = someRandomIntern.makeForm("ELSE", "None");
			std::cout << S->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}