/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:25:32 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 01:40:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
:	ClapTrap(), ScavTrap(), FragTrap()
{
	ClapTrap::setName("_clap_name");
	std::cout << "DiamondTrap constructor\n";
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
	std::cout << "ScavTrap default destructor name : ";
	std::cout << _name << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & D )
:	ClapTrap(D.getName() + "_clap_name", D.getHitPoint(),\
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

void	DiamondTrap::whoAmI() const
{
	std::cout << "I am " << _name << "(DiamondTrap)\n";
	_showPoints();
	std::cout << std::endl;
	std::cout << "attack damage : " << getAttackDamage();
	std::cout << std::endl;
}