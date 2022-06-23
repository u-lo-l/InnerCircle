/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:06:14 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/23 15:17:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	Phonebook	phonebook;
	std::string	cmd;
	bool		res;

	res = true;
	while (res == true)
	{
		std::cout << "ENTER command : ";
		std::getline(std::cin, cmd);
		if (std::cin.fail() == true)
			res = false;
		else if (cmd == "ADD")
			res = phonebook.addContact();
		else if (cmd == "SEARCH")
			res = phonebook.searchContact();
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "commands : [ADD, SEARCH, EXIT]" << std::endl;
	}
	if (res == false)
	{
		std::cout << "input error. quit program\n";
		return (1);
	}
	return (0);
}
