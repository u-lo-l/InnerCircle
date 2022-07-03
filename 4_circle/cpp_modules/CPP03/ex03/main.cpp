/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:38:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/03 23:50:40 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap	a;
	DiamondTrap	b("Morgan");
	ClapTrap	c("Hugues");
	ScavTrap	d("Ben");

	// std::cout << c << std::endl;
	// std::cout << d << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	std::cout << "\033[32m Who Am I?\033[0m" << std::endl;
	b.whoAmI();
	std::cout << "\033[32m take 3 dmg\033[0m" << std::endl;
	b.takeDamage(3);
	std::cout << "\033[32m take 20 dmg\033[0m" << std::endl;
	b.takeDamage(20);
	std::cout << "\033[32m repair 3\033[0m" << std::endl;
	b.beRepaired(3);

	std::cout << "\033[32m attack A1\033[0m" << std::endl;
	b.attack("A1");
	std::cout << "\033[32m attack A2\033[0m" << std::endl;
	b.attack("A2");
	std::cout << "\033[32m attack A3\033[0m" << std::endl;
	b.attack("A3");
	
	std::cout << "\033[32m repair 100\033[0m" << std::endl;
	b.beRepaired(100);
	std::cout << "\033[32m attack Eric\033[0m" << std::endl;
	b.attack("Eric");
}