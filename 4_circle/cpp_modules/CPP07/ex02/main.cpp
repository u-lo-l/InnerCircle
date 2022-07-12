/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:25:38 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/12 23:51:23 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
void showArray( Array<T> A )
{
	for (unsigned int i = 0 ; i <= A.getSize() ; i++)
	{
		try
		{
			std::cout << A[i] << std::endl;
		}
		catch (std::out_of_range & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}


template <typename T>
void showConstArray( const Array<T> & A )
{
	for (unsigned int i = 0 ; i <= A.getSize() ; i++)
	{
		try
		{
			std::cout << A[i] << std::endl;
		}
		catch (std::out_of_range & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

int main()
{
	Array<int> arr(4);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;

	showArray( arr );
	showConstArray( arr );

	Array<std::string> strarr(5);
	strarr[0] = "AAA";
	strarr[1] = "BBB";
	strarr[2] = "CCC";
	strarr[3] = "DDD";
	strarr[4] = "EEE";

	showArray( strarr );
	showConstArray( strarr );
}