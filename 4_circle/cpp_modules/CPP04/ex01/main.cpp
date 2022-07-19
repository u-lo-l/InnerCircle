/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:46:42 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 16:54:09 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <sstream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void setAnimal(Animal ** animal)
{
	int r = rand() % 3;
	switch (r)
	{
	case 0 :
		*animal = new Cat();
		break ;
	case 1 :
		*animal = new Dog();
		break ;
	case 2 :
		setAnimal(animal);
		break ;
	default:
		break;
	}
}

int main()
{
	{
		std::cout << "\033[1;3;33mSingle Construct test\033[0m" << std::endl;
		Animal * dog = new Dog;
		dog->makeSound();
		delete dog;
	}
	{
		std::cout << "\033[1;3;33mDeep Copy test1\033[0m" << std::endl;
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
		dog_cpy->addIdea("idea #11");
		std::cout << dog->getIdea(10) << std::endl;
		std::cout << dog_cpy->getIdea(10) << std::endl;
		delete dog;
		delete dog_cpy;
	}
	{
		std::cout << "\033[1;3;33mDeep Copy test2\033[0m" << std::endl;
		Dog * dog = new Dog();
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
		Dog * dog_cpy = new Dog(*dog);
		for (int i = 0 ; i < 10 ; i++)
			std::cout << dog_cpy->getIdea(i) << std::endl;
		dog_cpy->addIdea("idea #11");
		std::cout << dog->getIdea(10) << std::endl;
		std::cout << dog_cpy->getIdea(10) << std::endl;
		delete dog;
		delete dog_cpy;
	}
	{
		std::cout << "\033[1;3;33mSubject test\033[0m" << std::endl;
		const int NUMOFANIMALS = 7;
		srand(time(NULL));
		Animal ** animals = new Animal*[NUMOFANIMALS];

		std::cout << "setting animals" << std::endl;
		for (int i = 0 ; i < NUMOFANIMALS ; i++)
			setAnimal(&animals[i]);
		std::cout << std::endl;

		std::cout << "make sounds" << std::endl;
		for (int i = 0 ; i < NUMOFANIMALS ; i++)
			(animals[i])->makeSound();
		std::cout << std::endl;
		for (int i = 0 ; i < NUMOFANIMALS ; i++)
			delete animals[i];
		delete [] animals;
	}
	// system("leaks animal");
	return (0);
}