/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:59:37 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 01:41:07 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// protected member function
void	ClapTrap::_showPoints( void ) const
{
	std::cout << "hitpoint : " << _hitPoint;
	std::cout << " energypoint : " << _energyPoint;
}

// Cosntruct, Destruct
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor\n";
}

ClapTrap::ClapTrap( std::string name, int h, int e, int a)
: _name(name), _hitPoint(h), _energyPoint(e), _attackDamage(a)
{
	std::cout << "ClapTrap constructor with name : ";
	std::cout << _name << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap default destructor name : ";
	std::cout << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & c)
{
	std::cout << "ClapTrap copy constructor\n";
	this->setName(c.getName());
	this->setHitPoint(c.getHitPoint());
	this->setEnergePoint(c.getEnergePoint());
	this->setAttackDamage(c.getAttackDamage());
}

ClapTrap & ClapTrap::operator=(const ClapTrap & c)
{
	std::cout << "ClapTrap operator=\n";
	this->setName(c.getName());
	this->setHitPoint(c.getHitPoint());
	this->setEnergePoint(c.getEnergePoint());
	this->setAttackDamage(c.getAttackDamage());
	return (*this);
}

// setter
void	ClapTrap::setName( std::string name )
{	this->_name = name; }
void	ClapTrap::setHitPoint( int amount )
{	this->_hitPoint = amount; }
void	ClapTrap::setEnergePoint( int amount )
{	this->_energyPoint = amount; }
void	ClapTrap::setAttackDamage( int amount )
{	this->_attackDamage = amount; }
// getter
std::string		ClapTrap::getName( void ) const
{	return (_name); }
int	ClapTrap::getHitPoint( void ) const
{	return (_hitPoint); }
int	ClapTrap::getEnergePoint( void ) const
{	return (_energyPoint); }
int	ClapTrap::getAttackDamage( void ) const
{	return (_attackDamage); }

// methods
void	ClapTrap::attack( const std::string & target )
{
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "ClapTrap | " << _name;
		std::cout << " Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "ClapTrap | " << _name <<  " attacks ";
	std::cout << target << ", causing " << _attackDamage;
	std::cout << " points of damage!\n";
	_energyPoint -= ClapTrap::_COST;
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void	ClapTrap::takeDamage( int amount )
{
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "ClapTrap | " << _name;
		std::cout << " Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	std::cout << "ClapTrap | " << _name <<  " got ";
	std::cout << amount << " damages\n";
	_hitPoint = std::max(0, _hitPoint - amount);
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}

void	ClapTrap::beRepaired( int amount )
{
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "ClapTrap | " << _name;
		std::cout << " Not enough point -> ";
		_showPoints();
		std::cout << std::endl;
		return ;
	}
	_hitPoint = std::min(10, _hitPoint + amount);
	_energyPoint -= ClapTrap::_COST;
	std::cout << "ClapTrap | " << _name <<  " repaired ";
	std::cout << amount << " hitpoints\n";
	std::cout << "\tremain points -> ";
	_showPoints();
	std::cout << std::endl;
}