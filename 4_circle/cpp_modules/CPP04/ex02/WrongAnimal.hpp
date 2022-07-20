/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:20:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 15:20:04 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal(const std::string & animaltype = "");
	~WrongAnimal();
	WrongAnimal( const WrongAnimal & A );
	WrongAnimal & operator=( const WrongAnimal & A );
	void makeSound( void ) const;

	std::string getType() const;
};

#endif