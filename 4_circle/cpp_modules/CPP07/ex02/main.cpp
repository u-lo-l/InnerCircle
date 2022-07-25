/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:25:38 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/22 20:19:49 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
void showArray( Array<T> A )
{
	for (unsigned int i = 0 ; i <= A.size() ; i++)
	{
		try
		{
			std::cout << A[i] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}


template <typename T>
void showConstArray( const Array<T> & A )
{
	for (unsigned int i = 0 ; i <= A.size() ; i++)
	{
		try
		{
			std::cout << A[i] << std::endl;
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

int main()
{
	std::cout << "\033[1;3;33mset Array<int>\033[0m" << std::endl;
	Array<int> arr(4);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;

	std::cout << "\033[1;3;33mShow Array<int>\n\033[0m" << std::endl;
	showArray( arr );
	std::cout << "\033[1;3;33mShow Array<int> as const\033[0m" << std::endl;
	showConstArray( arr );

	std::cout << "\033[1;3;33mset Array<string>\033[0m" << std::endl;
	Array<std::string> strarr(5);
	strarr[0] = "AAA";
	strarr[1] = "BBB";
	strarr[2] = "CCC";
	strarr[3] = "DDD";
	strarr[4] = "EEE";

	std::cout << "\033[1;3;33mShow Array<string>\033[0m" << std::endl;
	showArray( strarr );
	std::cout << "\033[1;3;33mShow Array<string> as const\033[0m" << std::endl;
	showConstArray( strarr );
}