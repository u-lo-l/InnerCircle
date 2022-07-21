/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:38:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 19:00:40 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h> // for uintptr_t


struct Data
{
	int a;
	std::string b;
	float c;
};

inline uintptr_t serialize( Data * ptr)
{
	return (reinterpret_cast<uintptr_t>( ptr ));
}

inline Data * deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data *>( raw ));
}

int main()
{
	{
		Data	*ptr = new Data;
		Data	*ptr2;
		uintptr_t	raw;

		ptr->a = 10;
		ptr->b = "sampe string";
		ptr->c = 123.45f;
		std::cout << "Original data : \n";
		std::cout << "	addr : " << ptr << " : " << reinterpret_cast<unsigned long>(ptr) << std::endl;
		std::cout << "	a : " << ptr->a <<", b : " << ptr->b << ", c : " << ptr->c << std::endl;
		raw = serialize(ptr);
		std::cout << "Serialized -> " << raw << std::endl;
		ptr2 = deserialize(raw);
		std::cout << "   New   data : \n";
		std::cout << "	addr : " << ptr2 << " : " << reinterpret_cast<unsigned long>(ptr2) << std::endl;
		std::cout << "	a : " << ptr2->a << ", b : " << ptr2->b << ", c : " << ptr2->c << std::endl;

		delete ptr;
	}
	system("leaks reinterpret");
}
