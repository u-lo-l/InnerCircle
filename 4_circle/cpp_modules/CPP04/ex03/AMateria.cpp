/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:33:14 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 02:11:00 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( std::string const & type ) : _name(type)
{
	std::cout << "AMateria : Contructor with string called\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria : Default Destructor called\n";
}

std::string	const & AMateria::getType( void ) const
{
	return (_name);
}