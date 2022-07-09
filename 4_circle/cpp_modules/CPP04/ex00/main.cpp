/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:46:42 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 02:22:53 by dkim2            ###   ########.fr       */
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
		std::cout << "=============================\n";
		std::cout << "\033[3;33mDog, Cat Default Constructor\033[0m\n";
		Animal ani;
		Dog dog;
		Cat cat;
		ani.makeSound();
		dog.makeSound();
		cat.makeSound();
	}
	{
		std::cout << "=============================\n";
		std::cout << "\033[3;33mCopy Constructor\033[0m\n";
		Animal ani;
		// Dog dog;
		Cat cat;
		Animal ani2(ani);
		// Dog dog2(dog);
		Cat cat2(cat);
		ani2.makeSound();
		// dog2.makeSound();
		cat2.makeSound();
	}
	{
		std::cout << "=============================\n";
		std::cout << "\033[3;33mAssing operator\033[0m\n";
		Animal ani;
		// Dog dog;
		Cat cat;
		Animal ani2 = ani;
		// Dog dog2 = dog;
		Cat cat2 = cat;
		ani2.makeSound();
		// dog2.makeSound();
		cat2.makeSound();
	}
	{
		std::cout << "=============================\n";
		std::cout << "\033[3;31mWrong Animal Copy\033[0m\n";
		WrongAnimal wani;
		WrongAnimal wcat = WrongCat();
		WrongAnimal wani2(wani);
		WrongAnimal	wcat2(wcat);
		wani2.makeSound();
		wcat2.makeSound();
	}
	{
		std::cout << "=============================\n";
		std::cout << "\033[3;31mWrong Animal Assign\033[0m\n";
		WrongAnimal wani;
		WrongAnimal	wcat = WrongCat();
		wani.makeSound();
		wcat.makeSound();
	}
	{
		std::cout << "=============================\n";
		std::cout << "\033[3;33mAnimal Assign\033[0m\n";
		Animal ani;
		Animal cat = Cat();
		ani.makeSound();
		cat.makeSound();
	}
	{
		std::cout << "=============================\n";
		std::cout << "\033[3;33mAnimal Assign\033[0m\n";
		Animal * ani = new Animal();
		Animal * cat = new Cat();
		ani->makeSound();
		cat->makeSound();
		delete ani;
		delete cat;
	}
	return (0);
	
}