/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:33:15 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/22 16:09:40 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "test with single character" << std::endl;
		char a = '$';
		char b = '%';

		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\t<swap>\n";
		::swap(a, b);
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\tmin : " << ::min(a,b) << std::endl;
		std::cout << "\tmax : " << ::max(a,b) << std::endl;
	}

	{
		std::cout << "test with integer number" << std::endl;
		int a = 2;
		int b = 30;
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\t<swap>\n";
		::swap(a, b);
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\tmin : " << ::min(a,b) << std::endl;
		std::cout << "\tmax : " << ::max(a,b) << std::endl;
	}

	{
		std::cout << "test with floating point number" << std::endl;
		float a = 42.42;
		float b = 24.24;
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\t<swap>\n";
		::swap(a, b);
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\tmin : " << ::min(a,b) << std::endl;
		std::cout << "\tmax : " << ::max(a,b) << std::endl;
	}

	{
		std::cout << "test with const string" << std::endl;
		const std::string a = "ABCDEFG";
		const std::string b = "OPQRSTU";
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\tmin : " << ::min(a, b) << std::endl;
		std::cout << "\tmax : " << ::max(a, b) << std::endl;
	}

}
