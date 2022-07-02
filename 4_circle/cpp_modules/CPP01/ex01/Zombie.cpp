/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:02:03 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/27 12:50:53 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {}

Zombie::~Zombie( void )
{
	std::cout << "(R I P] : " << _name << std::endl;
}

void Zombie::announce( void ) const
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ\n";
}

void Zombie::setname( std::string name )
{
	_name = name;
}