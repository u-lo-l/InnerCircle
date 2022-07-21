/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:37:24 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 15:28:18 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "\033[3m";
	std::cout << "Intern Defalut Constructor called\n";
	std::cout << "\033[0m";
}

Intern::Intern( const Intern & I )
{
	(void)I;
	std::cout << "\033[3m";
	std::cout << "Intern Copy Constructor called\n";
	std::cout << "\033[0m";
}

Intern::~Intern()
{
	std::cout << "\033[3m";
	std::cout << "Intern Defalut Destructor called\n";
	std::cout << "\033[0m";
}

Intern & Intern::operator=( const Intern & I )
{
	std::cout << "\033[3m";
	std::cout << "Intern Assign operation called\n";
	std::cout << "\033[0m";
	if (this == &I)
		return (*this);
	return (*this);
}

Form * Intern::makeForm( const std::string & formtype, const std::string & target)
{
	const std::string TYPES[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
	};
	
	Form * (Intern::*maker[3])(const std::string & target) =
	{
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	
	for (int i = 0 ; i < 3 ; i++)
	{
		if (formtype == TYPES[i])
		{
			std::cout << formtype << "creates" << target << std::endl;
			return ((this->*maker[i])(target));
		}
	}
	std::cout << "Cannot find form type" << std::endl;
	throw (makeFormException());
	return (NULL);
}

Form * Intern::makeShrubberyCreationForm( const std::string & target )
{
	return (new ShrubberyCreationForm(target));
}
Form * Intern::makeRobotomyRequestForm( const std::string & target )
{
	return (new RobotomyRequestForm(target));
}
Form * Intern::makePresidentialPardonForm( const std::string & target )
{
	return (new PresidentialPardonForm(target));
}

const char * Intern::makeFormException::what() const throw()
{
	return ("\033[3;31mFailed to make Form\033[0m");
}