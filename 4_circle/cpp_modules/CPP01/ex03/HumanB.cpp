/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:09:38 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 18:45:55 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
: _weapon(0) {}

HumanB::HumanB(const std::string & name)
: _name(name), _weapon(0) {}

HumanB::~HumanB(){}

void HumanB::attack( void )
{
	if (!_weapon)
		std::cout << _name << " has no weapon\n";
	else
	{
		std::cout << _name << " attacks with their ";
		std::cout << _weapon->getType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon & weapon)
{
	_weapon = &weapon;
}
