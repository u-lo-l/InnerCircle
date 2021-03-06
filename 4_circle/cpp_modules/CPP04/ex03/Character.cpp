/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:04:19 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 18:24:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _equipCnt(0)
{
	for (int i = 0 ; i < Character::_SLOTSIZE ; i++)
		_slot[i] = NULL;
	std::cout << "Character : Default Constructor called\n";
}

Character::Character( const std::string & name ) : _equipCnt(0), _name(name)
{
	for (int i = 0 ; i < Character::_SLOTSIZE ; i++)
		_slot[i] = NULL;
	std::cout << "Character : Constructor with string called\n";
}

Character::Character( const Character & C )
{
	_equipCnt = C.getCnt();
	_name = C.getType();
	for (int i = 0 ; i < _equipCnt ; i++)
		_slot[i] = C._slot[i];
	std::cout << "Character : Copy Constructor called\n";
}

Character::~Character()
{
	std::cout << "Character : Default Destructor called\n";
}

Character & Character::operator=( const Character & C )
{
	if ( this == &C )
		return ( *this );
	_equipCnt = C.getCnt();
	_name = C.getType();
	for (int i = 0 ; i < _equipCnt ; i++)
		_slot[i] = C._slot[i];
	return ( *this );
}

const std::string & Character::getType() const
{
	return (_name);
}
int Character::getCnt() const
{
	return (_equipCnt);
}

void Character::equip(AMateria* m)
{
	if (_equipCnt >= Character::_SLOTSIZE)
	{
		std::cout << "Character(" << _name << ") : Inventory is full\n";
		return ;
	}
	_slot[_equipCnt++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _equipCnt)
	{
		std::cout << "\033[3;31m";
		std::cout << "Character : Invalid index\n";
		std::cout << "\033[0m";
		return ;
	}
	for (int i = idx ; i < Character::_SLOTSIZE ; i++)
		_slot[i] = _slot[i + 1];
	_equipCnt--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= _equipCnt)
	{
		std::cout << "\033[3;31m";
		std::cout << "Character : Invalid index\n";
		std::cout << "\033[0m";
		return ;
	}
	_slot[idx]->use(target);
}

const AMateria * Character::getElement( int idx ) const
{
	if (idx < 0 || idx >= Character::_SLOTSIZE)
		return (NULL);
	return (_slot[idx]);
}

void	Character::showInventory( void ) const
{
	std::cout << "Name : " << _name << " ";
	if (_equipCnt == 0)
		std::cout << "Inventory is empty" << std::endl;
	else
	{
		std::cout << "Invectory list" << std::endl;
		for (int i = 0 ; i < _equipCnt ; i++)
		{
			std::cout << "\t# : " << i << " " << _slot[i]->getType();
			std::cout << " : " << reinterpret_cast<void *>(_slot[i])<< std::endl;
		}
	}		
}
