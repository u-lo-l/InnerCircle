/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:59:30 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 21:20:11 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	std::cout << "==============[Ice Creating]" << std::endl ;
	Ice ice;
	std::cout << "=============[Cure Creating]" << std::endl;
	Cure cure;

	std::cout << "===========[Char 1 Creating]" << std::endl;
	Character c1("AAA");
	std::cout << "===========[Char 2 Creating]" << std::endl;
	Character c2("BBB");
	std::cout << "===========[Equip ice to c1 ]" << std::endl;
	c1.equip(&ice);
	std::cout << "===========[c1 use ice to c2 ]" << std::endl;
	c1.use(0, c2);
	std::cout << "===========[Equip cure to c1]" << std::endl;
	c1.equip(&cure);
	std::cout << "===========[c1 use cure to c2]" << std::endl;
	c1.use(1, c2);
	std::cout << "===========[c1 use wrong idx]" << std::endl;
	c1.use(-1, c1);
	c1.use(4, c1);
}

// void main()
// {
// 	IMateriaSource * src = new MateriaSource();

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
	
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
	
// 	tmp = src->createMateria("ice");
// 	std::cout << "\tice meteria addr : " << (tmp) << std::endl;
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	std::cout << "\tcure meteria addr : " << (tmp) << std::endl;
// 	me->equip(tmp);
// 	me->showInventory();
// 	ICharacter* bob = new Character("bob");
	
// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;
	
// 	system("leaks materia");
// }

// void main()
// {
// 	MateriaSource * src = new MateriaSource();

// 	src->learnMateria(new Ice());

// 	MateriaSource * cpy = new MateriaSource();
// 	std::cout << "[COPY!]" <<std::endl;
// 	(*cpy) = (*src);
// 	std::cout << "[COPY DONE!]" <<std::endl;
// 	delete src;

// 	AMateria * tmp;
// 	ICharacter * me  = new Character("me");
// 	ICharacter * bob = new Character("bob");
	

// 	cpy->learnMateria(new Cure());

// 	tmp = cpy->createMateria("cure");
// 	me->equip(tmp);
// 	me->use(0, *bob);

// 	delete tmp;

// 	tmp = cpy->createMateria("ice");
// 	me->equip(tmp);
// 	me->use(1, *bob);
	
// 	delete tmp;
// 	delete cpy;
// 	delete me;
// 	delete bob;

// 	system("leaks materia");
// }