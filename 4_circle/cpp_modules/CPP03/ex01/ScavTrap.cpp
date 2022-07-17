/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:43:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/17 20:07:00 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(const std::string & name)
	: ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor with name : ";
	std::cout << this->getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor name : ";
	std::cout << this->getName() << std::endl;
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
		std::cout << "ScavTrap " << getName();
		std::cout << " cannot attack. Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() <<  " attacks ";
	std::cout << target << ", causing " << getAttackDamage();
	std::cout << " points of damage!\n";
	setEnergePoint(getEnergePoint() - 1);
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void	ScavTrap::takeDamage( int amount )
{
	if (_hitPoint == 0)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " is already dead. Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name <<  " got ";
	std::cout << amount << " damages\n";
	_hitPoint = std::max(0, _hitPoint - amount);
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void	ScavTrap::beRepaired( int amount )
{
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " cannot repair. Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	_hitPoint = std::min(10, _hitPoint + amount);
	_energyPoint--;
	std::cout << "ScavTrap " << _name <<  " repaired ";
	std::cout << amount << " hitpoints\n";
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gatekeeper mode\n";
}
