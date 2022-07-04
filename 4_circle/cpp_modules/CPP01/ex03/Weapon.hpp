/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:35:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:08:12 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon
{
private :
	std::string _type;
public :
	Weapon( void );
	Weapon( std::string type );
	~Weapon( void );
	const std::string & getType( void );
	void setType( std::string type );
};
