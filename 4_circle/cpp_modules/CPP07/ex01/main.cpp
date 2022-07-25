/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:54:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/22 19:41:38 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void display(const T & a)
{
	std::cout << "<" << a << ">" << std::endl;
}

// template<typename T>
// void double_element( T & a )
// {
// 	a = a + a;
// }

// int main()
// {
// 	{
//                 int A[4] = {10, 9, 8, 7};
//                 iter(A, 4, display<const int>);
//                 // iter(A, 4, double_element<int>);
//                 iter(A, 4, display<const int>);
// 	}
// 	{
// 		std::string A[4] = {"AAA", "BBB", "CCC", "DDD"};
// 		iter(A, 4, display<std::string>);
// 		// iter(A, 4, double_element<std::string>);
// 		iter(A, 4, display<std::string>);
// 	}
// }

// int main()
// {
// 	{
//                 int A[4] = {10, 9, 8, 7};
//                 iter(A, 4, display);
//                 // iter(A, 4, double_element);
//                 iter(A, 4, display);
// 	}
// 	{
// 		std::string A[4] = {"AAA", "BBB", "CCC", "DDD"};
// 		iter(A, 4, display);
// 		// iter(A, 4, double_element);
// 		iter(A, 4, display);
// 	}
// }


class   Awesome {
private:
	int     _n;
public:
	Awesome( void ) : _n(42) { return;};
	int get( void ) const {return this->_n;};
};

std::ostream& operator<<(std::ostream& out, Awesome const& rhs) {
	out << rhs.get();
	return out;
}

template <typename T> // print here is declared at templated function 
void    print(const T & x) {
	std::cout << x << std::endl;
	return ;
}

// main.cpp 

int main() {
	int tab[]= {0,1,2,3,4};
	Awesome tab2[5];
	
	// print is used here without instantiation. invalid
	iter(tab, 5, print);
	iter(tab2, 5, print);
}