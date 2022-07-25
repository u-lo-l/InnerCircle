/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:21:14 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/23 13:13:37 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

template< typename T >
typename T::iterator easyfind(T & arr, const int & a)
{
	struct cannotFind : public std::exception
	{
		const char * what() const throw()
		{
			return ("Can't find value");
		}
	};
    typename T::iterator target = std::find(arr.begin(), arr.end(), a);
    if (target == arr.end())
        throw cannotFind();
    return (target);
}

