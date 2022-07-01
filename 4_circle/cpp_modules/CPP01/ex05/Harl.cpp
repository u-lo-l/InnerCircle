/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:50:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/01 19:24:07 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

const std::string Harl::_levels[4] = 
{
	"DEBUG", "INFO", "WARNING", "ERROR"
};

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::_debug( void )
{
	std::cout << "<HARL> debug message\n";
}
void	Harl::_info( void )
{
	std::cout << "<HARL> info message\n";
}
void	Harl::_warning( void )
{
	std::cout << "<HARL> waring message\n";
}
void	Harl::_error( void )
{
	std::cout << "<HARL> error message\n";
}

void	Harl::complain( std::string level )
{
	int	i;

	for (i = 0 ; i < 4 ; i++)
	{
		if (_levels[i] == level)
			break;
	}
	if (i >= 4)
		return ;
	// _complains[i]();
}