/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:20:45 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/03 02:53:11 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public :
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap & c);
	~ScavTrap();
	ScavTrap & operator=(const ScavTrap & c);
	void attack(const std::string & target);
	void guardGate( void );
};

#endif