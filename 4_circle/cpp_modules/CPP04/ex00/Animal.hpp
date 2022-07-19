/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:20:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 15:17:01 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
protected:
	std::string	_type;
public:
	Animal( const std::string & animaltype = "");
	virtual ~Animal();
	Animal( const Animal & A );
	Animal & operator=( const Animal & A );
	virtual void makeSound( void ) const;

	std::string getType() const;
};

#endif