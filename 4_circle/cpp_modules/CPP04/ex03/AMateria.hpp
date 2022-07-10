/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:59:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 02:10:34 by dkim2            ###   ########.fr       */
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
public :
	explicit AMateria( std::string const & type );
	virtual ~AMateria();
	
	std::string	const & getType( void ) const ;
	virtual AMateria * clone() const = 0;
	virtual void use(ICharacter & target) = 0;
};

#endif