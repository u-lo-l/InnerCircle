#include "Contact.hpp"
#include <iomanip>

bool		Contact::fillContact()
{
	std::cout << "\tEnter the first name     : ";
	std::getline(std::cin, _names[0]);
	if (std::cin.fail() == true)
		return (false);
	std::cout << "\tEnter the last name      : ";
	std::getline(std::cin, _names[1]);
	if (std::cin.fail() == true)
		return (false);
	std::cout << "\tEnter the nickname       : ";
	std::getline(std::cin, _names[2]);
	if (std::cin.fail() == true)
		return (false);
	std::cout << "\tEnter the phone number   : ";
	std::getline(std::cin, _phoneNumber);
	if (std::cin.fail() == true)
		return (false);
	std::cout << "\tEnter the darkest secret : ";
	std::getline(std::cin, _darkestSecret);
	if (std::cin.fail() == true)
		return (false);
	return (true);
}

void	Contact::printNames() const
{
	std::cout << std::setiosflags(std::ios::right);
	for (int i = 0 ; i < 3 ; i++)
	{
		std::cout << std::setw(10);
		if (_names[i].length() > 10)
			std::cout << _names[i].substr(0, 9) + ".";
		else
			std::cout << _names[i];
		std::cout << "|";
	}
	std::cout << std::endl;
}
