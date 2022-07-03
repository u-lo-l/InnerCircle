/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:59:39 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/03 22:54:35 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap
{
private:
	std::string		_name;
	int				_hitPoint;
	int				_energyPoint;
	int				_attackDamage;
protected :
	static const int	_COST = 1;
	void				_showPoints( void ) const;
public:
	ClapTrap();
	ClapTrap(std::string name, int h = 10, int e = 10, int a = 0);
	virtual ~ClapTrap( void );
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
	
	virtual void	attack( const std::string & target );
	void			takeDamage( int amount );
	void			beRepaired( int amount );
};

#endif