/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:36:41 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 01:36:30 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( const FragTrap & c );
	virtual ~FragTrap();
	FragTrap & operator=(const FragTrap & c);
	
	virtual void	attack(const std::string & target);
	void			highFivesGuys( void );
};

#endif