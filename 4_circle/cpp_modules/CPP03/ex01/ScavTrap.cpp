/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:43:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/03 12:27:51 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor with name : ";
	std::cout << getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor name : ";
	std::cout << getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & c)
	: ClapTrap(c.getName(), c.getHitPoint(),\
				c.getEnergePoint(), c.getAttackDamage())
{
	std::cout << "ScavTrap copy constructor\n";
}

ScavTrap & ScavTrap::operator=(const ScavTrap & c)
{
	std::cout << "ScavTrap operator=\n";
	setName(c.getName());
	setHitPoint(c.getHitPoint());
	setEnergePoint(c.getEnergePoint());
	setAttackDamage(c.getAttackDamage());
	return (*this);
}

void ScavTrap::attack(const std::string & target)
{
	if (getHitPoint() == 0 || getEnergePoint() == 0)
	{
		std::cout << "ScavTrap | " << getName();
		std::cout << " Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "ScavTrap | " << getName() <<  " attacks ";
	std::cout << target << ", causing " << getAttackDamage();
	std::cout << " points of damage!\n";
	setEnergePoint(getEnergePoint() - ScavTrap::_COST);
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap | " << getName() << "is now in Gatekeeper mode\n";
}