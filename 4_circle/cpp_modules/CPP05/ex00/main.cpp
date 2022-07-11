/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:09:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 04:53:50 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main ()
{
	{
		std::cout << "================CASE 1================" << std::endl;
		try
		{
			Bureaucrat one("Jack", 75);
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
			Bureaucrat one("Jack", 190);
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
			Bureaucrat one("Jack", 150);
			one.increaseGrade();
			one.decreaseGrade();
			one.decreaseGrade();
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
			Bureaucrat one("Jack", 30);
			one.increaseGrade(29);
			one.increaseGrade(1);
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
			Bureaucrat one("Jack", 70);
			Bureaucrat two("Hong", 70);
			Bureaucrat three(one);
			three.decreaseGrade(30);
			std::cout << one << std::endl << two << std::endl << three << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "================CASE 6================" << std::endl;
		try 
		{
			Bureaucrat one("Jack", 100);
			one.increaseGrade(50);
			Bureaucrat two("Hong");
			two = one;
			one.increaseGrade(40);
			two.decreaseGrade(40);
			std::cout << one << std::endl << two << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}