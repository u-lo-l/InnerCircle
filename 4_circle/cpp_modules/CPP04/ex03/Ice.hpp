/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 06:09:18 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 06:12:11 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( const Ice & I );
	virtual ~Ice( void );
	Ice		&operator=( const Ice &other );
	virtual AMateria	*clone( void ) const ;
	virtual void		use(ICharacter& target);
};

#endif