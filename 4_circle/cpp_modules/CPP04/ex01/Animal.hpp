/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:20:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 16:45:51 by dkim2            ###   ########.fr       */
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

	virtual void addIdea(const std::string & idea ) const = 0;
	virtual std::string getIdea( unsigned int i ) const = 0;
};

#endif