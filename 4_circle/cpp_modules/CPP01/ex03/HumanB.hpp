/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:49:43 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:07:16 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
# include "Weapon.hpp"

class HumanB
{
private :
	std::string _name;
	Weapon * _weapon;
public :
	HumanB(std::string name);
	~HumanB();
	void attack( void );
	void setWeapon(Weapon * weapon);
};

#endif
