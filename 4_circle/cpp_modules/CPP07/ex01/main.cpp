/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:54:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 23:46:03 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void display(const T & a);


int main()
{
	{
		int A[4] = {10, 9, 8, 7};
		iter(A, 4, display);
	}
	{
		std::string A[4] = {"AAA", "BBB", "CCC", "DDD"};
		iter(A, 4, display);
	}
}

template <typename T>
void display(const T & a)
{
	std::cout << "<" << a << ">" << std::endl;
}
