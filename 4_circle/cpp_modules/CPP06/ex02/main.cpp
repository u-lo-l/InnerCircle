/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:03:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/12 15:59:59 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base * generate( void );

void identify( Base * p );

void identify( Base & p);

int main()
{
	Base *b;

	std::cout << "Identify by pointer (10times)\n";
	for (int i = 0 ; i < 10; i++)
	{
		std::cout << "#" << i << " : ";
		b = generate();
		if (b == NULL)
			continue;
		std::cout << " -> ";
		identify(b);
		std::cout << std::endl;
		delete b;
	}

	std::cout << "Identify by reference (10times)\n";
	for (int i = 0 ; i < 10; i++)
	{
		std::cout << "#" << i << " : ";
		b = generate();
		if (b == NULL)
			continue;
		std::cout << " -> ";
		identify(*b);
		std::cout << std::endl;
		delete b;
	}
}

Base * generate( void )
{
	int	random = rand() % 3;
	
	switch (random)
	{
	case 0 :
		std::cout << "generate A ";
		return (new A());
	case 1 : 
		std::cout << "generate B ";
		return (new B());
	default :
		std::cout << "generate C ";
		return (new C());
	}
}

void identify( Base * p )
{
	A *a;
	B *b;
	C *c;
	
	a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "type : A";
	
	b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "type : B";
	
	c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "type : C";
}

void identify( Base & p)
{
	A a;
	B b;
	C c;
	
	try
	{
		a = dynamic_cast< A & >(p);
		std::cout << "type : A";
	}
	catch(...)
	{	}
	
	try
	{
		b = dynamic_cast< B &>(p);
		std::cout << "type : B";
	}
	catch (...)
	{	}
	
	try
	{
		c = dynamic_cast< C &>(p);
		std::cout << "type : C";
	}
	catch (...)
	{	}
}