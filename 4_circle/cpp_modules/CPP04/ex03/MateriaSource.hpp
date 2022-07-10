/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:35:15 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 01:45:49 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
private :
	const static int _SLOTSIZE = 4;
	AMateria * _slot[MateriaSource::_SLOTSIZE];
public :
	MateriaSource();
	MateriaSource( const MateriaSource & M );
	virtual ~MateriaSource();
	MateriaSource & operator=( const MateriaSource & M );

	virtual void learnMateria(AMateria * A);
	virtual AMateria * createMateria( const std::string & type );

	const AMateria * getElement(int idx) const ;
};

#endif