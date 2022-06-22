/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:55 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/22 18:18:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <string>
#include <iomanip>

Phonebook::Phonebook ()
{	
	_numOfConts = 0;
	_oldestIndex = 0;
}

Phonebook::~Phonebook () {};

void	Phonebook::addContact(void)
{
	if (_numOfConts < MAXCONTS)
	{
		_contacts[_numOfConts] = Contact();
		_contacts[_numOfConts].fillContact();
		_numOfConts++;
	}
	else
	{
		_contacts[_oldestIndex] = Contact();
		_contacts[_oldestIndex].fillContact();
		_oldestIndex++;
		_oldestIndex %= MAXCONTS;
	}
}

void	Phonebook::searchContact(void) const
{
	int idx;

	if (_numOfConts == 0)
	{
		std::cout << "Phonebook is empty\n";
		return ;
	}
	std::cout << "Enter index to print :";
	std::cin >> idx;
	if (std::cin.fail())
	{
		std::cout << "WRONG FORMAT\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return ;
	}
	if (idx < 0 || idx >= _numOfConts)
		std::cout << "INDEX OUT OF RANGE\n";
	else
	{
		std::cout << std::setw(10) << idx << "|";
		_contacts[idx].printNames();
	}
}
