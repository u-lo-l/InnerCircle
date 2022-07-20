/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:37:22 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 13:57:47 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public :
	Intern();
	Intern( const Intern & I );
	~Intern();
	Intern & operator=( const Intern & I );

	Form * makeForm( const std::string & formtype, const std::string & target );
	Form * makeShrubberyCreationForm( const std::string & target );
	Form * makeRobotomyRequestForm( const std::string & target );
	Form * makePresidentialPardonForm( const std::string & target );
};

#endif