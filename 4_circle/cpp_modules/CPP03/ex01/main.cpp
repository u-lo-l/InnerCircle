/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:38:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 19:10:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::string s1 = "CLAP";
	std::string s2 = "SCAV";
	{
		ClapTrap * claptrap = new ClapTrap(s1);
		ScavTrap * scavtrap = new ScavTrap(s2);

		std::cout << std::endl;
		claptrap->attack(s2);
		scavtrap->takeDamage(0);
		scavtrap->beRepaired(18);
		std::cout << std::endl;

		scavtrap->attack(s1);
		claptrap->takeDamage(20);
		scavtrap->attack(s1);
		claptrap->takeDamage(20);

		scavtrap->attack(s1);
		claptrap->beRepaired(64);
		std::cout << std::endl;

		scavtrap->guardGate();

		scavtrap->attack(s1);
		std::cout << std::endl;

		scavtrap->takeDamage(100);
		scavtrap->takeDamage(1);
		
		scavtrap->attack(s2);
		scavtrap->beRepaired(200);
		
		std::cout << std::endl;
		delete scavtrap;
		delete claptrap;
	}
	std::cout << "==========================" << std::endl;
	{
		ClapTrap claptrap = ScavTrap(s2);
		claptrap.attack(s1);
		// claptrap.guardGate(); --> invalid
	}
	std::cout << "=========================" << std::endl;
	{
		ClapTrap * scavClap = new ScavTrap(s2);
		scavClap->attack("s1");
		// scavClap->guardGate(); --> invalid
		delete scavClap;
	}
	return (0);
}
