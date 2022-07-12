/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:26:52 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/12 22:38:41 by dkim2            ###   ########.fr       */
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
}

template <typename T>
T	min(const T & a, const T & b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T	max(const T & a, const T & b)
{
	if (a > b)
		return a;
	else
		return b;
}
