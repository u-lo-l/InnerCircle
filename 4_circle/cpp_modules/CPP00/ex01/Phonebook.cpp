/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:55 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:02:44 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>
#include <iomanip>

Phonebook::Phonebook ()
{	
	_numOfConts = 0;
	_oldestIndex = 0;
}

Phonebook::~Phonebook () {}

bool	Phonebook::addContact(void)
{
	int	targetIndex;

	if (_numOfConts < MAXCONTS)
		targetIndex = _numOfConts;	
	else
		targetIndex = _oldestIndex;
	if (_contacts[targetIndex].fillContact() == false)
	{
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

static int	receive_index(int numberOfContacts);

bool	Phonebook::searchContact(void) const
{
	int 		idx;
	
	if (_numOfConts == 0)
	{
		std::cout << "\tPhonebook is empty\n";
		return (true);
	}
	idx = receive_index(_numOfConts);
	if (idx == -1)
		return (false);
	std::cout << std::setw(10) << idx << "|";
	_contacts[idx].printNames();
	return (true);
}

static int	receive_index(int noc)
{
	int idx;

	while (true)
	{
		std::cout << "\tEnter index to print : ";
		std::cin >> idx;
		if (std::cin.eof() == true)
			return (-1);
		if (std::cin.fail() == true || std::cin.get() != '\n')
		{
			std::cout << "\t<err>Wrong format\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (idx < 0 || idx >= noc)
			std::cout << "\t<err>Index out of range : 0 ~ " << noc - 1 << std::endl;
		else
			return (idx);
	}
}
