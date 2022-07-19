/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:33:19 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 20:01:13 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
};

FragTrap::FragTrap(const std::string & name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor with name : ";
	std::cout << _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor name : ";
	std::cout << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap & c)
	: ClapTrap(c.getName(), c.getHitPoint(),\
				c.getEnergePoint(), c.getAttackDamage())
{
	std::cout << "FragTrap copy constructor\n";
}

FragTrap & FragTrap::operator=(const FragTrap & c)
{
	std::cout << "FragTrap operator=\n";
	setName(c.getName());
	setHitPoint(c.getHitPoint());
	setEnergePoint(c.getEnergePoint());
	setAttackDamage(c.getAttackDamage());
	return (*this);
}

void FragTrap::attack(const std::string & target)
{
	if (getHitPoint() == 0 || getEnergePoint() == 0)
	{
		std::cout << "FragTrap " << getName();
		std::cout << " Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name <<  " attacks ";
	std::cout << target << ", causing " << _attackDamage;
	std::cout << " points of damage!\n";
	_energyPoint--;
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void	FragTrap::takeDamage( int amount )
{
	if (_hitPoint == 0)
	{
		std::cout << "FragTrap " << _name;
		std::cout << " is already dead. Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name <<  " got ";
	std::cout << amount << " damages\n";
	_hitPoint = std::max(0, _hitPoint - amount);
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void	FragTrap::beRepaired( int amount )
{
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "FragTrap " << _name;
		std::cout << " cannot repair. Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	_hitPoint = std::min(100, _hitPoint + amount);
	_energyPoint--;
	std::cout << "FragTrap " << _name <<  " repaired ";
	std::cout << amount << " hitpoints\n";
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap : High five~\n";
}
