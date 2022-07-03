/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:33:19 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 01:37:55 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor with name : ";
	std::cout << getName() << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor name : ";
	std::cout << getName() << std::endl;
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

void	FragTrap::attack(const std::string & target)
{
	if (getHitPoint() == 0 || getEnergePoint() == 0)
	{
		std::cout << "FragTrap | " << getName();
		std::cout << " Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "FragTrap | " << getName() <<  " attacks ";
	std::cout << target << ", causing " << getAttackDamage();
	std::cout << " points of damage!\n";
	setEnergePoint(getEnergePoint() - FragTrap::_COST);
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap : High five~\n";
}
