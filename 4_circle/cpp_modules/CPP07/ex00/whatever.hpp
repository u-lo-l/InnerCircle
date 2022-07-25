/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:26:52 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/22 16:12:06 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T & a, T & b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
	// a = a + a;
	// b = b + a;
}

template <typename T>	// const
T	min(const T & a, const T & b)
{
	// std::cout << "min with const called\n";
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>	// non const
T	min(T & a, T & b)
{
	// std::cout << "min with non const called\n";
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>	// const
T	max(const T & a, const T & b) 
{
	// std::cout << "max with const called\n";
	if (a > b)
		return a;
	else
		return b;
}

template <typename T>	// non const
T	max(T & a, T & b)
{
	// std::cout << "max with non const called\n";

	if (a > b)
		return a;
	else
		return b;
}
