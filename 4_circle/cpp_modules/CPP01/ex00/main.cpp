/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:17:36 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 11:49:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "======Zombie in Heap=======\n";
	{
		Zombie * p_zombieInHeap;
		p_zombieInHeap = new Zombie("Hombie");
		p_zombieInHeap->announce();
		delete p_zombieInHeap;
	}
	std::cout << "======Zombie in Stack======\n";
	{
		Zombie zombieInStack("Sombie");
		zombieInStack.announce();
	}
	std::cout << "=========new Zombie========\n";
	{
		Zombie * p_nombie = newZombie("Nombie");
		p_nombie->announce();
		delete p_nombie;
		std::cout << "========random Chump=======\n";
		randomChump("Rombie");
	}
	// system("leaks zombie");
	return (0);
}
