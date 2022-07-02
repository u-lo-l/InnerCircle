/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:09:38 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/27 16:20:16 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}

void HumanB::attack( void )
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon * weapon)
{
	_weapon = weapon;
}
