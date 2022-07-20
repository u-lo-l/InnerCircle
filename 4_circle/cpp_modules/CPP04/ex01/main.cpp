/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:46:42 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 12:35:02 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "\033[1;3;33mSingle Construct test\033[0m" << std::endl;
		Animal * dog = new Dog;
		dog->makeSound();
		delete dog;
	}
	{
		std::cout << "\033[1;3;33mDeep Copy test(fail)\033[0m" << std::endl;
		Animal * dog = new Dog();
		Animal * dog_cpy = new Dog();
		for (int i = 0 ; i < 10 ; i++)
		{
			std::stringstream ss;
			ss << (i+1);
			std::string idea;
			ss >> idea;
			idea = "idea #" + idea;
			dog->addIdea(idea);
		}
		for (int i = 0 ; i < 10 ; i++)
			std::cout << dog->getIdea(i) << std::endl;
		(*dog_cpy) = (*dog);
		for (int i = 0 ; i < 10 ; i++)
			std::cout << dog_cpy->getIdea(i) << std::endl;
		dog_cpy->addIdea("new idea");
		std::cout << dog->getIdea(10) << std::endl;
		std::cout << dog_cpy->getIdea(0) << std::endl;
		
		delete dog;
		delete dog_cpy;
	}
	{
		std::cout << "\033[1;3;33mDeep Copy test dog\033[0m" << std::endl;
		Dog * dog = new Dog();
		for (int i = 0 ; i < 10 ; i++)
		{
			std::stringstream ss;
			ss << (i+1);
			std::string idea;
			ss >> idea;
			idea = "dog idea #" + idea;
			dog->addIdea(idea);
		}
		for (int i = 0 ; i < 10 ; i++)
			std::cout << dog->getIdea(i) << std::endl;
		Dog * dog_cpy = new Dog(*dog);
		for (int i = 0 ; i < 10 ; i++)
			std::cout << dog_cpy->getIdea(i) << std::endl;
		dog_cpy->addIdea("new idea");
		std::cout << dog->getIdea(10) << std::endl;
		std::cout << dog_cpy->getIdea(10) << std::endl;
		delete dog;
		delete dog_cpy;
	}
	{
		std::cout << "\033[1;3;33mDeep Copy test cat\033[0m" << std::endl;
		Cat * cat = new Cat();
		for (int i = 0 ; i < 10 ; i++)
		{
			std::stringstream ss;
			ss << (i+1);
			std::string idea;
			ss >> idea;
			idea = "cat idea #" + idea;
			cat->addIdea(idea);
		}
		for (int i = 0 ; i < 10 ; i++)
			std::cout << cat->getIdea(i) << std::endl;
		Cat * cat_cpy = new Cat(*cat);
		for (int i = 0 ; i < 10 ; i++)
			std::cout << cat_cpy->getIdea(i) << std::endl;
		cat_cpy->addIdea("new idea");
		std::cout << cat->getIdea(10) << std::endl;
		std::cout << cat_cpy->getIdea(10) << std::endl;
		delete cat;
		delete cat_cpy;
	}
	{
		std::cout << "\033[1;3;33mSubject test(Animal Array)\033[0m" << std::endl;
		const int NUMOFANIMALS = 5;
		Animal * animals[NUMOFANIMALS];

		std::cout << "setting animals" << std::endl;
		for (int i = 0 ; i < NUMOFANIMALS ; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog;
			else
				animals[i] = new Cat;
		}
		std::cout << std::endl;
		
		std::cout << "make sounds" << std::endl;
		for (int i = 0 ; i < NUMOFANIMALS ; i++)
			(animals[i])->makeSound();
			
		std::cout << std::endl;
		for (int i = 0 ; i < NUMOFANIMALS ; i++)
			delete animals[i];
	}
	system("leaks animal");
	return (0);
}