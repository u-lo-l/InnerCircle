/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:06:14 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/01 17:31:35 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	Phonebook	phonebook;
	std::string	cmd;
	bool		res;

	res = true;
	while (res == true)
	{
		std::cout << "ENTER command [ADD, SEARCH, EXIT] : ";
		std::getline(std::cin, cmd);
		if (std::cin.fail() == true)
			res = false;
		else if (cmd == "ADD")
			res = phonebook.addContact();
		else if (cmd == "SEARCH")
			res = phonebook.searchContact();
		else if (cmd == "EXIT")
			break;
	}
	if (res == false)
	{
		std::cout << "<err>input error. quit program\n";
		return (1);
	}
	return (0);
}
