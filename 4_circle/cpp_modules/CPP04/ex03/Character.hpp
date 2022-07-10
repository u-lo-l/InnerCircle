/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:32:29 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 02:12:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class AMateria;

class Character : public ICharacter
{
private :
	const static int _SLOTSIZE = 4;
	int _equipCnt;
	AMateria * _slot[Character::_SLOTSIZE];
	std::string _name;
	Character();
public :
	explicit Character( const std::string & name );
	Character( const Character & C );
	virtual ~Character();
	Character & operator=( const Character & C );

	virtual std::string const & getType() const;
	int	getCnt() const;
	
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	const AMateria * getElement( int idx ) const;
};

#endif