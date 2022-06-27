/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:23:00 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/27 14:32:01 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	str("HI THIS IS BRAIN");
	std::string * stringPTR = &str;
	std::string & stringREF = str;
	
	std::cout << "======================================" << std::endl;
	std::cout << "mem address of  str   : " << &str << std::endl;
	std::cout << "mem address of strPTR : " << &stringPTR << std::endl;
	std::cout << "mem address of strREF : " << &stringREF << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "value of  str   : " << str << std::endl;
	std::cout << "value of strPTR : " << *stringPTR << std::endl;
	std::cout << "value of strREF : " << stringREF << std::endl;
	std::cout << "======================================" << std::endl;
	return (0);
}