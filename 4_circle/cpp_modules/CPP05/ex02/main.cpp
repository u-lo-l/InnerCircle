/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:09:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 10:04:09 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
int main ()
{
	{
		std::cout << "================CASE 1================" << std::endl;
		try
		{
			Bureaucrat one("Geo", 30);
			ShrubberyCreationForm S = ShrubberyCreationForm("berry");
			S.beSigned(one);
			S.execute(one);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "================CASE 2================" << std::endl;
		try
		{
			srand(time(NULL));
			Bureaucrat one("Geo", 30);
			RobotomyRequestForm B[10] = {
				RobotomyRequestForm("A231CE"),
				RobotomyRequestForm("Z5E34F"),
				RobotomyRequestForm("C003CB"),
				RobotomyRequestForm("ZFE1CE"),
				RobotomyRequestForm("BF32V4"),
				RobotomyRequestForm("EFZ1C4"),
				RobotomyRequestForm("BF34K4"),
				RobotomyRequestForm("FU31F4"),
				RobotomyRequestForm("YF3TC4"),
				RobotomyRequestForm("OP1CE0")
			};
			for (int i = 0 ; i < 10 ; i++)
				B[i].beSigned(one);
			for (int i = 0 ; i < 10 ; i++)
				B[i].execute(one);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "================CASE 3================" << std::endl;
		try
		{
			srand(time(NULL));
			Bureaucrat one("Geo", 130);
			RobotomyRequestForm B = RobotomyRequestForm("A231CE");
			B.beSigned(one);
			B.execute(one);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "================CASE 4================" << std::endl;
		try
		{
			srand(time(NULL));
			Bureaucrat one("Geo", 3);
			PresidentialPardonForm P = PresidentialPardonForm("Kaey");
			P.beSigned(one);
			P.execute(one);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "================CASE 5================" << std::endl;
		try
		{
			srand(time(NULL));
			Bureaucrat one("Geo", 10);
			PresidentialPardonForm P = PresidentialPardonForm("Kaey");
			P.beSigned(one);
			P.execute(one);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}