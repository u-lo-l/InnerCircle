/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:47:55 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 11:05:22 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>
#include <iomanip>
#include <sstream>

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
		if (std::cin.fail() == false)
		{
			std::cin.clear();
			return (true);
		}
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
	std::cout << "\033[5m     index| firstname|  lastname|  nickname|\033[0m\n";
	for (int i = 0 ; i < _numOfConts ; i++)
	{
		std::cout << std::setw(10) << i << "|";
		_contacts[i].printNames();
	}
	idx = receive_index(_numOfConts);
	if (idx == -1)
		return (false);
	std::cout << "Index        : " << idx << std::endl;
	_contacts[idx].printInfos();
	return (true);
}

static int	receive_index(int noc)
{
	while (true)
	{
		std::cout << "\tEnter index to print : ";
		std::string line;
		std::getline(std::cin, line);
		if (std::cin.eof() == true)
			return (-1);
		else if (line == "")
		{
			std::cout << "empty!";
			continue ;
		}
		std::istringstream iss(line);
		int idx;
		iss >> idx;
		if (iss.fail() == true || iss.eof() == false)
			std::cout << "\t<err>Wrond format\n";
		else if (idx < 0 || idx >= noc)
			std::cout << "\t<err>Index out of range : 0 ~ " << noc - 1 << std::endl;
		else
			return (idx);
	}
}
