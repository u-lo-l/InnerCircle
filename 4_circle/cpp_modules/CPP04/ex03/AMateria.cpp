/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:33:14 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 17:54:00 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _name("")
{
	std::cout << "AMateria : Defalut Contructor called\n";
}

AMateria::AMateria( std::string const & type ) : _name(type)
{
	std::cout << "AMateria : Contructor with string(type : " << type << ") called\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria : Default Destructor called\n";
}

std::string	const & AMateria::getType( void ) const
{
	return (_name);
}