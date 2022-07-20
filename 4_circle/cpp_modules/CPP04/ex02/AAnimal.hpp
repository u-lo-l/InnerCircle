/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:20:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 17:40:35 by dkim2            ###   ########.fr       */
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
	AAnimal( const std::string & animaltype = "");
	virtual ~AAnimal();
	AAnimal( const AAnimal & A );
	AAnimal & operator=( const AAnimal & A );
	virtual void makeSound( void ) const = 0;
	std::string getType() const;

	virtual void addIdea(const std::string & idea ) const = 0;
	virtual std::string getIdea( unsigned int i ) const = 0;
};

#endif