/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:41:23 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 18:46:37 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{}

Weapon::Weapon( const std::string & type) : _type(type)
{}

Weapon::~Weapon( void ) {}

const std::string & Weapon::getType( void ) const
{
	return (_type);
}
void Weapon::setType( const std::string & type )
{
	_type = type;
}
