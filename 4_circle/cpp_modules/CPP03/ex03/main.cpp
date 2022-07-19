/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:38:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 20:12:05 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap	b("DIAM");

	std::cout << "=============Who Am I? ===============" << std::endl;
	b.whoAmI();
	std::cout << std::endl << "=============take 3 dmg ==============" << std::endl;
	b.takeDamage(3);
	std::cout << std::endl << "=============take 20 dmg =============" << std::endl;
	b.takeDamage(20);
	std::cout << std::endl << "=============repair 3 ================" << std::endl;
	b.beRepaired(3);

	std::cout << std::endl << "=============attack A1 ===============" << std::endl;
	b.attack("A1");
	std::cout << std::endl << "=============attack A2 ===============" << std::endl;
	b.attack("A2");
	std::cout << std::endl << "=============attack A3 ===============" << std::endl;
	b.attack("A3");
	
	std::cout << std::endl << "=============repair 100 ==============" << std::endl;
	b.beRepaired(100);
	std::cout << std::endl << "=============attack Eric =============" << std::endl;
	b.attack("ERIC");
}