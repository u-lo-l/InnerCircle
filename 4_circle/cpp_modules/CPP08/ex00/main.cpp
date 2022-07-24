/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:21:16 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/23 13:30:23 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> arr(100);
	for (int i = 0 ; i < 100 ; i++)
		arr[i] = i + 3;
	try
	{
		std::vector<int>::iterator p = easyfind(arr, 40);
		std::cout << *p << std::endl;		
		std::cout << (*easyfind(arr, 35)) << std::endl;
		std::cout << (*easyfind(arr, 57)) << std::endl;
		std::cout << (*easyfind(arr, 24)) << std::endl;
		std::cout << (*easyfind(arr, 64)) << std::endl;
		std::cout << (*easyfind(arr, 100)) << std::endl;
		std::cout << (*easyfind(arr, 200)) << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
}
