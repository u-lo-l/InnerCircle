/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:34:09 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 09:58:01 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequestForm", _GRADETOSIGN, _GRADETOEXEC), _target("")
{
	std::cout << "\033[3m";
	std::cout << "RobotomyRequestForm Default Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
: Form("RobotomyRequestForm", _GRADETOSIGN, _GRADETOEXEC), _target(target)
{
	std::cout << "\033[3m";
	std::cout << "RobotomyRequestForm Default Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & S )
: Form("RobotomyRequestForm", _GRADETOSIGN, _GRADETOEXEC), _target(S.getTarget())
{
	std::cout << "\033[3m";
	std::cout << "RobotomyRequestForm Copy Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[3m";
	std::cout << "RobotomyRequestForm Default Denstructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm & S )
{
	std::cout << "\033[3m";
	std::cout << "RobotomyRequestForm Assign operator called\n";
	(void)&S;
	std::cout << *this << std::endl;
	std::cout << "\033[0m";
	return (*this);
}

const std::string & RobotomyRequestForm::getTarget( void ) const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecutable(executor);

	std::cout << "Drrrrrrrrrrrrrr!!!!\n";
	if (rand() % 2)
		std::cout << _target << " robotomization failed\n";
	else
		std::cout << _target << " robotomization successed\n";
}

std::ostream & operator<<(std::ostream & os, const RobotomyRequestForm & S )
{
	if (S.getTarget() == "")
		os << "Anonymous RobotomyRequestForm\n";
	else
	{
		os << "\ttarget : " << S.getTarget();
		os << "\n\tsigned : " <<  (S.getSign() ? "TRUE" : "FALSE");
		os << "\n\tGrade to sign : " <<  S.getG2S();
		os << "\n\tGrade to execute: " <<  S.getG2E() << std::endl;
	}
	return (os);
}