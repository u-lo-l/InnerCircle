/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:02:03 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 15:39:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "empty Zombie crated" << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << _name << " crated" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << _name << " : destroyed" << std::endl;
}

void Zombie::announce( void ) const
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ...\n";
}
