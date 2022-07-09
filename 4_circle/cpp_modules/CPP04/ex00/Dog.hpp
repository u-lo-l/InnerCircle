/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:32:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 01:32:13 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
public :
	Dog();
	virtual ~Dog();
	Dog( const Dog & D );
	virtual Dog & operator=(const Dog & D);
	virtual void makeSound( void ) const;
};

#endif