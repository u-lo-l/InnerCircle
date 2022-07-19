/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:46:42 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 15:27:33 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "\033[1;3;33msubject test\033[0m" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout << "\033[1;3;33mWrongAnimal test\033[0m" << std::endl;
		const WrongAnimal * wrongMeta = new WrongAnimal();
		const WrongAnimal * wrongCat = new WrongCat();
		wrongCat->makeSound();

		delete wrongMeta;
		delete wrongCat;
	}
	// system("leaks animal");
	return (0);
}