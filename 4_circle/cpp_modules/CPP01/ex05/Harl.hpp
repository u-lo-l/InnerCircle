/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:52:16 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/01 19:22:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <string>

class Harl
{
private :
	static const std::string	_levels[4];
	void	(*_complains[4])(void);
	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );
public :
	Harl();
	~Harl();
	void	complain( std::string level );
};

#endif