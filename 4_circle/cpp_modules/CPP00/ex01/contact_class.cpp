#include "contact.hpp"
#include <iomanip>

void		Contact::fillContact()
{
	std::cout << "Enter the first name: ";
	std::getline(std::cin, _names[0]);
	std::cout << "Enter the last name: ";
	std::getline(std::cin, _names[1]);
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, _names[2]);
	std::cout << "Enter the phone number: ";
	std::getline(std::cin, _phoneNumber);
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, _darkestSecret);
	std::cout << "done!" << std::endl;
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