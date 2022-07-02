/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:47:29 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/27 15:57:32 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H
# include "Weapon.hpp"

class HumanA
{
private :
	std::string _name;
	Weapon & _weapon;
public :
	HumanA(std::string name, Weapon & weapon);
	~HumanA();
	void attack( void );
};

#endif
