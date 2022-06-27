/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:55 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/27 11:48:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <string>
#include <iomanip>

Phonebook::Phonebook ()
{	
	_numOfConts = 0;
	_oldestIndex = 0;
}

Phonebook::~Phonebook () {};

bool	Phonebook::addContact(void)
{
	int	targetIndex;

	if (_numOfConts < MAXCONTS)
		targetIndex = _numOfConts;	
	else
		targetIndex = _oldestIndex;
	if (_contacts[targetIndex].fillContact() == false)
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "\n\tfail to add contact\n";
		return (false);
	}
	if (_numOfConts < MAXCONTS)
		_numOfConts++;
	else
		++_oldestIndex %= MAXCONTS;
	std::cout << "\tcontact added\n";
	return (true);
}

bool	Phonebook::searchContact(void) const
{
	int idx;

	if (_numOfConts == 0)
	{
		std::cout << "\tPhonebook is empty\n";
		return (true);
	}
	while (true)
	{
		std::cout << "\tEnter index to print : ";
		(std::cin >> idx).get();
		if (std::cin.good() == true)
		{
			if (idx < 0 || idx >= _numOfConts)
			{
				std::cout << "\tINDEX OUT OF RANGE : 0 ~ " << _numOfConts - 1 << std::endl;
				continue ;
			}
			else
			{
				std::cout << std::setw(10) << idx << "|";
				_contacts[idx].printNames();
				break;
			}
		}
		if (std::cin.fail() == true && std::cin.eof() == true)
			return (false);
		std::cout << "\tWRONG FORMAT\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	return (true);
}
