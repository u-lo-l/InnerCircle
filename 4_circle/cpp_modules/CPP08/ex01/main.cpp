/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:10:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/24 17:33:42 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	Span span(20);
	for (int i = 0 ; i < 20 ;i++)
	{
		try
		{
			span.addNumber(i * 2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cerr << i << std::endl;
			break;
		}
	}
	std::cout << span.getSize() << std::endl;
}