/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:47:03 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 02:52:02 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor called\n";
	for (int i = 0 ; i < MateriaSource::_SLOTSIZE ; i++)
		_slot[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & M )
{
	std::cout << "MateriaSource Copy Constructor called\n";
	for (int i = 0 ; i < MateriaSource::_SLOTSIZE ; i++)
		_slot[i] = M.getElement(i)->clone();
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Copy Constructor called\n";
	for (int i = 0 ; i < MateriaSource::_SLOTSIZE ; i++)
	{
		if (_slot[i] != NULL)
			delete _slot[i];
	}
}

MateriaSource & MateriaSource::operator=( const MateriaSource & M )
{
	std::cout << "MateriaSource Assign Operator called\n";
	if (this == &M)
		return (*this);
	for (int i = 0 ; i < MateriaSource::_SLOTSIZE ; i++)
	{
		std::cout << "\033[3m\tcopying Materia #" << i << " : \033[0m";
		if (M.getElement(i) == NULL)
		{
			std::cout << "NULL\033[0m\n";
			_slot[i] = NULL;
		}
		else
		{
			delete _slot[i];
			std::cout << "\033[3mtype : " << M.getElement(i)->getType() << "\033[0m" << std::endl;
			_slot[i] = M.getElement(i)->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria * A)
{
	std::cout << "trying to learn Materia : " << A->getType() << std::endl;
	for (int i = 0 ; i < MateriaSource::_SLOTSIZE ; i++)
	{
		if (_slot[i] == NULL)
		{
			_slot[i] = A;
			return ;
		}
	}
}

AMateria * MateriaSource::createMateria( const std::string & type )
{
	std::cout << "trying to create Materia : " << type << std::endl;
	for (int i = 0 ; i < MateriaSource::_SLOTSIZE ; i++)
	{
		if (_slot[i] != NULL && type == _slot[i]->getType())
			return (_slot[i]->clone());
	}
	std::cout << "FAIL : type not found\n";
	return (NULL);
}

const AMateria * MateriaSource::getElement(int idx) const
{
	if (idx < 0 || idx >= MateriaSource::_SLOTSIZE)
		return (NULL);
	return (_slot[idx]);
}