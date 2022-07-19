/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:32:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 16:45:08 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private :
	Brain * _pbrain;
public :
	Cat();
	virtual ~Cat();
	Cat( const Cat & C );
	virtual Cat & operator=( const Cat & C );
	virtual void makeSound( void ) const;
	virtual void addIdea(const std::string & idea ) const;
	virtual std::string getIdea( unsigned int i ) const;
};

#endif