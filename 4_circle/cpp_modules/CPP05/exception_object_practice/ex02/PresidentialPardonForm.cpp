/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:01:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 10:05:04 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardonForm", _GRADETOSIGN, _GRADETOEXEC), _target("")
{
	std::cout << "\033[3m";
	std::cout << "PresidentialPardonForm Default Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
: Form("PresidentialPardonForm", _GRADETOSIGN, _GRADETOEXEC), _target(target)
{
	std::cout << "\033[3m";
	std::cout << "PresidentialPardonForm Default Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & S )
: Form("PresidentialPardonForm", _GRADETOSIGN, _GRADETOEXEC), _target(S.getTarget())
{
	std::cout << "\033[3m";
	std::cout << "PresidentialPardonForm Copy Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[3m";
	std::cout << "PresidentialPardonForm Default Denstructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm & S )
{
	std::cout << "\033[3m";
	std::cout << "PresidentialPardonForm Assign operator called\n";
	(void)&S;
	std::cout << *this << std::endl;
	std::cout << "\033[0m";
	return (*this);
}

const std::string & PresidentialPardonForm::getTarget( void ) const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecutable(executor);
	std::cout << "\033[1;32m";
	std::cout << _target << " has been pardoned by Zafod Beeblebrox.\n";
	std::cout << "\033[0m";
}

std::ostream & operator<<(std::ostream & os, const PresidentialPardonForm & S )
{
	if (S.getTarget() == "")
		os << "Anonymous PresidentialPardonForm\n";
	else
	{
		os << "\ttarget : " << S.getTarget();
		os << "\n\tsigned : " <<  (S.getSign() ? "TRUE" : "FALSE");
		os << "\n\tGrade to sign : " <<  S.getG2S();
		os << "\n\tGrade to execute: " <<  S.getG2E() << std::endl;
	}
	return (os);
}