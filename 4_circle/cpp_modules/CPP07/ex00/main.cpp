/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:33:15 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/12 22:48:54 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
	{
		char a = '$';
		char b = '%';

		std::cout << "test case 1\n";
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\t<swap>\n";
		swap(a, b);
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\tmin : " << min(a,b) << std::endl;
		std::cout << "\tmax : " << max(a,b) << std::endl;
	}

	{
		int a = 2;
		int b = 30;
		std::cout << "test case 2\n";
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\t<swap>\n";
		swap(a, b);
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\tmin : " << min(a,b) << std::endl;
		std::cout << "\tmax : " << max(a,b) << std::endl;
	}

	{
		float a = 42.42;
		float b = 24.24;
		std::cout << "test case 3\n";
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\t<swap>\n";
		swap(a, b);
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\tmin : " << min(a,b) << std::endl;
		std::cout << "\tmax : " << max(a,b) << std::endl;
	}

	{
		std::string a = "ABCDEFG";
		std::string b = "OPQRSTU";
		std::cout << "test case 4\n";
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\t<swap>\n";
		swap(a, b);
		std::cout << "\ta : " << a << std::endl;
		std::cout << "\tb : " << b << std::endl;
		std::cout << "\tmin : " << ::min(a, b) << std::endl;
		std::cout << "\tmax : " << ::max(a, b) << std::endl;
	}
}
