/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:21:16 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 15:12:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
    {
        std::vector<int> arr(100);
        for (int i = 0 ; i < 100 ; i++)
            arr[i] = i + 3;
        try
        {
            std::vector<int>::iterator p = easyfind(arr, 40);
            std::cout << *p << std::endl;
        }
        catch(const char * errmsg)
        {
            std::cerr << errmsg << '\n';
        }
    }
    {

    }
}