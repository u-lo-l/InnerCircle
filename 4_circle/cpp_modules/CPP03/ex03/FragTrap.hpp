/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:36:41 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/18 20:11:27 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	FragTrap();
public:
	FragTrap(const std::string & name);
	FragTrap(const FragTrap & c);
	virtual ~FragTrap();
	FragTrap & operator=(const FragTrap & c);

	virtual void	attack(const std::string & target);
	virtual void	takeDamage( int amount );
	virtual void	beRepaired( int amount );
	
	void			highFivesGuys( void );
};

#endif