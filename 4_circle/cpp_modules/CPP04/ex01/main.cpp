/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:46:42 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 05:03:27 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	{
		Dog * doge = new Dog();


		(doge->getBrain())->setIdea("IDEA1");
		(doge->getBrain())->setIdea("IDEA2");
		(doge->getBrain())->setIdea("IDEA3");
		(doge->getBrain())->setIdea("IDEA4");
		std::cout << "index : " << (doge->getBrain())->getIndex() << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(0) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(1) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(2) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(3) << "]" << std::endl;
		
		Dog * dog = new Dog(*doge);
		dog->makeSound();
		std::cout << "========================================\n";
		std::cout << "index : " << (dog->getBrain())->getIndex() << std::endl;
		std::cout << "[" <<(dog->getBrain())->getIdea(0) << "]" << std::endl;
		std::cout << "[" <<(dog->getBrain())->getIdea(1) << "]" << std::endl;
		std::cout << "[" <<(dog->getBrain())->getIdea(2) << "]" << std::endl;
		std::cout << "[" <<(dog->getBrain())->getIdea(3) << "]" << std::endl;
		(dog->getBrain())->setIdea("IDEA5");
		(dog->getBrain())->setIdea("IDEA6");
		(dog->getBrain())->setIdea("IDEA7");
		(dog->getBrain())->setIdea("IDEA8");

		*doge = *dog;
		std::cout << "========================================\n";
		std::cout << "index : " << (dog->getBrain())->getIndex() << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(0) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(1) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(2) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(3) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(4) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(5) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(6) << "]" << std::endl;
		std::cout << "[" <<(doge->getBrain())->getIdea(7) << "]" << std::endl;
		std::cout << "\033[3;32mdog end\033[0m\n";
		delete dog;
		std::cout << "\033[3;32mdoge end\033[0m\n";
		delete doge;
	}
	{
		Dog doge;
		Dog dog;

		dog.makeSound();

		(doge.getBrain())->setIdea("IDEA1");
		(doge.getBrain())->setIdea("IDEA2");
		(doge.getBrain())->setIdea("IDEA3");
		(doge.getBrain())->setIdea("IDEA4");
		std::cout << "index : " << (doge.getBrain())->getIndex() << std::endl;
		std::cout << "[" <<(doge.getBrain())->getIdea(0) << "]" << std::endl;
		std::cout << "[" <<(doge.getBrain())->getIdea(1) << "]" << std::endl;
		std::cout << "[" <<(doge.getBrain())->getIdea(2) << "]" << std::endl;
		std::cout << "[" <<(doge.getBrain())->getIdea(3) << "]" << std::endl;
		
		dog = doge;
		std::cout << "========================================\n";
		std::cout << "index : " << (dog.getBrain())->getIndex() << std::endl;
		std::cout << "[" <<(dog.getBrain())->getIdea(0) << "]" << std::endl;
		std::cout << "[" <<(dog.getBrain())->getIdea(1) << "]" << std::endl;
		std::cout << "[" <<(dog.getBrain())->getIdea(2) << "]" << std::endl;
		std::cout << "[" <<(dog.getBrain())->getIdea(3) << "]" << std::endl;

		std::cout << "\033[3;32mdog end\033[0m\n";
		std::cout << "\033[3;32mdoge end\033[0m\n";
	}
	return (0);
}