/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:41:23 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:07:15 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {}

Weapon::Weapon( std::string type) : _type(type) {}

Weapon::~Weapon( void ) {}

const std::string & Weapon::getType( void )
{
	return (_type);
}
void Weapon::setType( std::string type )
{
	_type = type;
}
