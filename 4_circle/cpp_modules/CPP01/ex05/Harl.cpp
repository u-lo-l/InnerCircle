/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:41:23 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:13:27 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


const std::string Harl::_LEVEL[4] = {
	"DEBUG", "INFO", "WARNING", "ERROR"
};

void	Harl::_debug( void )
{
	std::cout << "I love having extra bacon for my &XL=double-cheese";
	std::cout << "-triple-pickle-special-ketchup burger. I really do!\n";
	std::cout << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "I cannot belive adding extra bacon costs more money.\n";
	std::cout << "You didn't put enought bacon in my burger!";
	std::cout << " If you did, I wouldn't be asking for more!\n";
	std::cout << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years whereas you started";
	std::cout << " working here since last month.\n";
	std::cout << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
	std::cout << std::endl;
}

Harl::Harl( void ) 
{
	_complaints[0] = &Harl::_debug;
	_complaints[1] = &Harl::_info;
	_complaints[2] = &Harl::_warning;
	_complaints[3] = &Harl::_error;
}

Harl::~Harl( void ) {}	

void	Harl::complain( std::string level)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (level == _LEVEL[i])
		{
			std::cout << ("[" + _LEVEL[i] + "]\n");
			(this->*_complaints[i])();
		}
	}
}
