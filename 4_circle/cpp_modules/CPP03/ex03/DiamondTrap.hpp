/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:17:56 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 19:36:14 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private :
	std::string _name;
public :
	DiamondTrap();
	DiamondTrap( std::string name );
	virtual ~DiamondTrap();
	DiamondTrap( const DiamondTrap & D );
	DiamondTrap & operator=( const DiamondTrap & D );

	virtual void	attack( const std::string & target );
	virtual void	takeDamage( int amount );
	virtual void	beRepaired( int amount );
	void			whoAmI() const;
};

#endif