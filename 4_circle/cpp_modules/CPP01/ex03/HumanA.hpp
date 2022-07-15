/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:47:29 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 18:12:50 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
private :
	std::string _name;
	Weapon & _weapon;
public :
	HumanA(const std::string & name, Weapon & weapon);
	~HumanA();
	void attack( void );
};

#endif
