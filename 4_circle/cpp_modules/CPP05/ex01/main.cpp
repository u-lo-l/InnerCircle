/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:09:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 07:06:51 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main ()
{
	{
		std::cout << "================CASE 1================" << std::endl;
		try
		{
			Bureaucrat one("Jack", 75);
			Form form(one.getName(), 200, 50);
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
			Bureaucrat one("Jack", 19);
			Form form(one.getName(), 20, 50);
			std::cout << "\033[4m";
			std::cout << "form attributes\n";
			std::cout << "NAME : " << form.getName() << std::endl;
			std::cout << "SIGNED : " << (form.getSign() ? "TRUE" : "FALSE") << std::endl;
			std::cout << "Grade to be signed : " << form.getG2S() << std::endl;
			std::cout << "Grade to execute : " << form.getG2E() << std::endl;
			std::cout << "\033[0m";

			form.beSigned(one);
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
			Bureaucrat one("Jack", 22);
			Form form("Son", 20, 50);
			std::cout << "\033[4m";
			std::cout << "form attributes\n";
			std::cout << "NAME : " << form.getName() << std::endl;
			std::cout << "SIGNED : " << (form.getSign() ? "TRUE" : "FALSE") << std::endl;
			std::cout << "Grade to be signed : " << form.getG2S() << std::endl;
			std::cout << "Grade to execute : " << form.getG2E() << std::endl;
			std::cout << "\033[0m";

			one.signForm(form);
			one.increaseGrade(5);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}