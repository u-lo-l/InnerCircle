/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:35:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 16:57:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
private :
	std::string _type;
public :
	Weapon( void );
	Weapon( const std::string & type );
	~Weapon( void );
	const std::string & getType( void ) const;
	void setType( const std::string & type );
};

#endif
