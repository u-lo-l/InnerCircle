/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 06:12:13 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 02:10:00 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( const Cure & I );
	virtual ~Cure( void );
	Cure & operator=( const Cure &other );
	virtual AMateria * clone( void ) const;
	virtual void use(ICharacter& target);
};

#endif