/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:32:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 12:06:45 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private :
	Brain * _pbrain;
public :
	Dog();
	virtual ~Dog();
	Dog( const Dog & D );
	Dog & operator=(const Dog & D);
	virtual void makeSound( void ) const;
	virtual void addIdea(const std::string & idea ) const;
	virtual std::string getIdea( unsigned int i ) const;
};

#endif