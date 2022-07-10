/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:59:30 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 02:55:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void test1()
{
	std::cout << "==============[Ice Creating]" << std::endl ;
	Ice ice;
	std::cout << "=============[Cure Creating]" << std::endl;
	Cure cure;

	std::cout << "===========[Char 1 Creating]" << std::endl;
	Character c1("AAA");
	std::cout << "===========[Char 2 Creating]" << std::endl;
	Character c2("BBB");
	std::cout << "===========[Equip ice to 1 ]" << std::endl;
	c1.equip(&ice);
	std::cout << "===========[1 use ice to 2 ]" << std::endl;
	c1.use(0, c2);
	std::cout << "===========[Equip cure to 1]" << std::endl;
	c1.equip(&cure);
	std::cout << "===========[1 use cure to 2]" << std::endl;
	c1.use(1, c2);
	std::cout << "===========[1 use wront idx]" << std::endl;
	c1.use(-1, c1);
}

void test2()
{
	IMateriaSource * src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}

void test3()
{
	MateriaSource * src = new MateriaSource();

	src->learnMateria(new Ice());

	MateriaSource * cpy = new MateriaSource();
	std::cout << "[COPY!]" <<std::endl;
	(*cpy) = (*src);
	std::cout << "[COPY DONE!]" <<std::endl;
	delete src;

	AMateria * tmp;
	// ICharacter me  = Character("me");
	// ICharacter bob = Character("bob");
	ICharacter * me  = new Character("me");
	ICharacter * bob = new Character("bob");
	

	cpy->learnMateria(new Cure());

	tmp = cpy->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);

	delete tmp;

	tmp = cpy->createMateria("ice");
	me->equip(tmp);
	me->use(1, *bob);
	
	delete tmp;
	delete cpy;
	delete me;
	delete bob;
}

int main()
{
	// test1();
	// test2();
	test3();
}