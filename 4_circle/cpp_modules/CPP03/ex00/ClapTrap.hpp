/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:59:39 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 14:39:30 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	int	_hitPoint;
	int	_energyPoint;
	int	_attackDamage;
	void	_showPoints( void );
public:
	ClapTrap();
	ClapTrap(const std::string & name);
	~ClapTrap( void );
	ClapTrap(const ClapTrap & c);
	ClapTrap & operator=(const ClapTrap & c);

	void	setName( std::string name );
	void	setHitPoint( int amount );
	void	setEnergePoint( int amount );
	void	setAttackDamage( int ammount );

	std::string	getName( void ) const;
	int			getHitPoint( void ) const;
	int			getEnergePoint( void ) const;
	int			getAttackDamage( void ) const;
	
	void	attack( const std::string & target );
	void	takeDamage( int amount );
	void	beRepaired( int amount );
};

#endif
