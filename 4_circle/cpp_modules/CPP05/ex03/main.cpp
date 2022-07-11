/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:09:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 11:02:32 by dkim2            ###   ########.fr       */
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
		std::cout << "================CASE 1================" << std::endl;
		try
		{
			Intern I;
			Form * S = I.makeForm(TYPES[0], "SSS");
			std::cout << S->getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}