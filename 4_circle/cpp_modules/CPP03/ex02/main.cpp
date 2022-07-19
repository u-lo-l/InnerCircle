/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:38:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 19:54:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::string s3 = "FRAG";

	// Constructors
	FragTrap fragtrap(s3);
	std::cout << std::endl;

	// Attacks 
	fragtrap.attack("MONSTER");
	std::cout << std::endl;

	// Frag::highFive
	fragtrap.highFivesGuys();
	std::cout << std::endl;

	// Repair
	fragtrap.beRepaired(18);

	// Take damage
	fragtrap.takeDamage(50);

	// Die
	fragtrap.takeDamage(50);

	// Do something after dying
	fragtrap.beRepaired(20);
	fragtrap.attack("MONSTER");

	std::cout << std::endl;
	return (0);
}