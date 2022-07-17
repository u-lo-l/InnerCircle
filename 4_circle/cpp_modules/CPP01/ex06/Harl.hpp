/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:35:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:13:51 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
private :
	const static std::string _LEVEL[5];
	void	(Harl::*_complaints[4])(void);
	
	void	_extra( void );
	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );
public :
	Harl( void );
	~Harl( void );
	bool 	complain( std::string level);
};
