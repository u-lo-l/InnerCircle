/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:52:22 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/22 18:52:20 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// template <typename T, typename F>
// void iter(T *arr, unsigned int size, F func)
// {
// 	if (func == 0)
// 		return;
// 	for (unsigned int i = 0 ; i < size ; i++)
// 		func(arr[i]);
// }

template <typename T>
void iter(const T * arr, unsigned int size, void (*func)( const T & ))
{
	if (func == 0)
		return;
	for (unsigned int i = 0 ; i < size ; i++)
		func(arr[i]);
}

// template <typename T>
// void iter(const T * arr, unsigned int size, void (*func)( T &))
// {
// 	if (func == 0)
// 		return;
// 	for (unsigned int i = 0 ; i < size ; i++)
// 		func(arr[i]);
// }

