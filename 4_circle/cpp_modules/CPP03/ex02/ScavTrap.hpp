/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:20:45 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 19:38:40 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public :
	ScavTrap();
	ScavTrap(const std::string & name);
	ScavTrap(const ScavTrap & c);
	virtual ~ScavTrap();
	ScavTrap & operator=(const ScavTrap & c);
	
	virtual void	attack(const std::string & target);
	virtual void	takeDamage( int amount );
	virtual void	beRepaired( int amount );
	
	void			guardGate( void );
};

#endif