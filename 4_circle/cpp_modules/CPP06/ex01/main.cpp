/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:38:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/12 07:56:24 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h> // for uintptr_t

struct Data
{
	int	a, b, c;
};

inline uintptr_t serialize( Data * ptr)
{
	return (uintptr_t(ptr));
}

inline Data * deserialize( uintptr_t raw )
{
	return ((Data *)(raw));
}

int main()
{
	Data	*ptr = new Data;
	Data	*ptr2;
	uintptr_t	raw;

	ptr->a = 10;
	ptr->b = 20;
	ptr->c = 30;
	std::cout << "Original data : ";
	std::cout << "a : " << ptr->a <<", b : " << ptr->b << ", c : " << ptr->c << std::endl;
	raw = serialize(ptr);
	ptr2 = deserialize(raw);
	std::cout << "   New   data : ";
	std::cout << "a : " << ptr2->a << ", b : " << ptr2->b << ", c : " << ptr2->c << std::endl;
}