/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:21:14 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 15:12:22 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

template< typename T >
typename T::iterator easyfind(T & arr, const int & a)
{
    typename T::iterator target = std::find(arr.begin(), arr.end(), a);
    if (target == arr.end())
        throw "Can't find value";
    return (target);
}