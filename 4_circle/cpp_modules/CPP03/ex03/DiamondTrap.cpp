/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:25:32 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 20:02:41 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
:	ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name )
:	ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(), FragTrap()
{
	_name = name;
	std::cout << "DiammonTrap constructor with name : ";
	std::cout << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor name : ";
	std::cout << _name << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & D )
:	ClapTrap(D.getName(), D.getHitPoint(),\
				D.getEnergePoint(), D.getAttackDamage()),
	ScavTrap(), FragTrap()
{
	_name = D.getName();
	std::cout << "DiamondTrap copy constructor\n";
}

DiamondTrap & DiamondTrap::operator=( const DiamondTrap & D )
{
	std::cout << "DiamondTrap operator=\n";
	_name = D.getName();
	setHitPoint(D.getHitPoint());
	setEnergePoint(D.getEnergePoint());
	setAttackDamage(D.getAttackDamage());
	return (*this);
}

void	DiamondTrap::attack( const std::string & target )
{
	ClapTrap::attack( target );
}

void	DiamondTrap::takeDamage( int amount )
{
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "DiamondTrap " << _name;
		std::cout << " already dead. Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << _name <<  " got ";
	std::cout << amount << " damages\n";
	_hitPoint = std::max(0, _hitPoint - amount);
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void	DiamondTrap::beRepaired( int amount )
{
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "DiamondTrap " << _name;
		std::cout << " cannot repair. Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	_hitPoint = std::min(100, _hitPoint + amount);
	_energyPoint--;
	std::cout << "DiamondTrap " << _name <<  " repaired ";
	std::cout << amount << " hitpoints\n";
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "I am " << _name << "(DiamondTrap)" << std::endl;
	std::cout << "and " << getName() << "(ClapTrap)" << std::endl;
}