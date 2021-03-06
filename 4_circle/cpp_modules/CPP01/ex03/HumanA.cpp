/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:51:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 18:12:30 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string & name, Weapon & weapon)
: _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack( void )
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
