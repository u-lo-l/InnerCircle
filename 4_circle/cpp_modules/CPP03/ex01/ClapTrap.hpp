/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:59:39 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/03 22:13:59 by dkim2            ###   ########.fr       */
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
	enum	{_COST = 1};
	void				_showPoints( void );
public:
	ClapTrap();
	ClapTrap(const std::string & name, int h = 10, int e = 10, int a = 0);
	virtual ~ClapTrap( void );
	ClapTrap(const ClapTrap & c);
	ClapTrap & operator=(const ClapTrap & c);

	void	setName( const std::string & name );
	void	setHitPoint( int amount );
	void	setEnergePoint( int amount );
	void	setAttackDamage( int ammount );

	std::string	getName( void ) const;
	int			getHitPoint( void ) const;
	int			getEnergePoint( void ) const;
	int			getAttackDamage( void ) const;
	
	virtual void	attack( const std::string & target );
	virtual void	takeDamage( int amount );
	virtual void	beRepaired( int amount );
};

#endif
