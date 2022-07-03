/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:38:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/03 01:53:03 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	const std::string s1 = "Tom";
	const std::string s2 = "Mot";
	const int d1 = 4;
	const int d2 = 5;

	ClapTrap claptrap1(s1);
	claptrap1.setAttackDamage(d1);
	ClapTrap claptrap2(s2);
	claptrap2.setAttackDamage(d2);

	std::cout << std::endl;
	claptrap1.attack(s2);
	claptrap2.takeDamage(d1);
	claptrap2.beRepaired(3);
	claptrap2.beRepaired(18);

	claptrap2.attack(s1);
	claptrap1.takeDamage(d2);
	claptrap2.attack(s1);
	claptrap1.takeDamage(d2);
	claptrap2.attack(s1);

	claptrap1.beRepaired(3);
	claptrap1.beRepaired(64);
	std::cout << std::endl;
	return (0);
}