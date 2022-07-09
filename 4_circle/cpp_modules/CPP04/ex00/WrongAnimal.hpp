/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:20:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 01:30:42 by dkim2            ###   ########.fr       */
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
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal( const WrongAnimal & A );
	WrongAnimal & operator=( const WrongAnimal & A );
	void makeSound( void ) const;

	std::string getType() const;
};

#endif