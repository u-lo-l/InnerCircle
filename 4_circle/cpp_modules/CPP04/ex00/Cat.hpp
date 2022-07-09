/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:32:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 01:30:58 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
public :
	Cat();
	virtual ~Cat();
	Cat( const Cat & D );
	virtual Cat & operator=(const Cat & D);
	virtual void makeSound( void ) const;
};

#endif