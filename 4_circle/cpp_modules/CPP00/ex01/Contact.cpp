#include "Contact.hpp"
#include <iomanip>

static bool checkContactField( const std::string & str)
{
	if (std::cin.fail() == true)
		return (false);
	if (str == "")
		return (false);
	return (true);
}

bool		Contact::fillContact()
{
	std::cout << "\tEnter the first name     : ";
	std::getline(std::cin, _names[0]);
	if (checkContactField(_names[0]) == false)
		return (false);
	std::cout << "\tEnter the last name      : ";
	std::getline(std::cin, _names[1]);
	if (checkContactField(_names[1]) == false)
		return (false);
	std::cout << "\tEnter the nickname       : ";
	std::getline(std::cin, _names[2]);
	if (checkContactField(_names[2]) == false)
		return (false);
	std::cout << "\tEnter the phone number   : ";
	std::getline(std::cin, _phoneNumber);
	if (checkContactField(_phoneNumber) == false)
		return (false);
	std::cout << "\tEnter the darkest secret : ";
	std::getline(std::cin, _darkestSecret);
	if (checkContactField(_darkestSecret) == false)
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

void	Contact::printInfos(void) const
{
	std::cout << "First name   : " << _names[0] << std::endl;
	std::cout << "Last name    : " << _names[1] << std::endl;
	std::cout << "Nickname     : " << _names[2] << std::endl;
	std::cout << "Phone number : " << _phoneNumber << std::endl;
	std::cout << "Secret       : " << _darkestSecret << std::endl;
}
