/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:55:34 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:05:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie
{
private :
	std::string _name;
public :
	Zombie( std::string name = "Anonymous");
	~Zombie( void );
	void announce( void );
	Zombie * newZombie( std::string name );
	void randomChump( std::string name );
};

#endif
