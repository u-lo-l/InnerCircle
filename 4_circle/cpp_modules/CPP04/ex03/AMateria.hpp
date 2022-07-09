/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 05:59:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 06:16:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <string>

class AMateria
{
protected:
	std::string _type;
public:
	AMateria();
	AMateria( std::string const & type);
	AMateria( const AMateria & A );
	virtual ~AMateria();
	AMateria	&operator=( const AMateria & A );
	virtual AMateria * clone() const = 0;
	virtual void use(ICharacter & target);
};

#endif