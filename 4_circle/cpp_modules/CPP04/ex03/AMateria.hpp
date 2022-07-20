/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:59:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 17:52:39 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria
{
protected :
	std::string _name;
	AMateria();
public :
	explicit AMateria( std::string const & type );
	virtual ~AMateria();
	
	std::string	const & getType( void ) const ;
	virtual AMateria * clone() const = 0;
	virtual void use(ICharacter & target) = 0;
};

#endif