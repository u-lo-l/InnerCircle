/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:02:03 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/27 12:17:08 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name) {}

Zombie::~Zombie( void )
{
	std::cout << "(R I P] : " << _name << std::endl;
}

void Zombie::announce( void )
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ\n";
}