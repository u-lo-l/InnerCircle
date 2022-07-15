/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:49:43 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 18:40:23 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
private :
	std::string _name;
	Weapon * _weapon;
public :
	HumanB();
	HumanB(const std::string & name);
	~HumanB();
	void attack( void );
	void setWeapon(Weapon & weapon);
};

#endif
