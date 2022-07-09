/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:20:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 06:27:23 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <string>

class AAnimal
{
protected:
	std::string	_type;
public:
	AAnimal();
	virtual ~AAnimal() = 0;
	AAnimal( const AAnimal & A );
	AAnimal & operator=( const AAnimal & A );
	virtual void makeSound( void ) const = 0;

	std::string getType() const;
};

#endif