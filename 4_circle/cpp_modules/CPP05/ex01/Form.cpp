/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 05:38:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 07:18:39 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form()
:_name(""), _gradeToSign(Form::_MINGRADE), _gradeToExec(Form::_MINGRADE)
{
	std::cout << "\033[3m";
	std::cout << "Form Default Constructor called\n";
	_sign = false;
	std::cout << *this << std::endl;
	std::cout << "\033[0m";
}

Form::Form(std::string name, unsigned int g2s, unsigned int g2e)
:_name(name), _gradeToSign(g2s), _gradeToExec(g2e)
{
	std::cout << "\033[3m";
	std::cout << "Form Default Constructor called\n";
	std::cout << "\033[0m";
	if (g2s > Form::_MINGRADE || g2e > Form::_MINGRADE)
		throw Form::GradeTooLowException();
	if (g2s < Form::_MAXGRADE || g2e < Form::_MAXGRADE)
		throw Form::GradeTooHighException();
	std::cout << "\033[3m";
	_sign = false;
	std::cout << *this << std::endl;
	std::cout << "\033[0m";
}

Form::Form( const Form & F )
:_name(F.getName()), _gradeToSign(F.getG2S()), _gradeToExec(F.getG2E())
{
	std::cout << "\033[3m";
	std::cout << "Form Copy Constructor called\n";
	_sign = F.getSign();
	std::cout << *this << std::endl;
	std::cout << "\033[0m";
}

Form::~Form()
{
	std::cout << "\033[3m";
	std::cout << "Form Default Destructor called\n";
	std::cout << *this << std::endl;
	std::cout << "\033[0m";
}

Form & Form::operator=( const Form & F )
{
	std::cout << "\033[3m";
	std::cout << "Form Assign operator called (" << _name << " <- " << F.getName() << ")\n";
	std::cout << "only sign will be copied. not name, gradeToSign, gradeToExec\n";
	this->_sign = F.getSign();
	std::cout << *this << std::endl;
	std::cout << "\033[0m";
	return (*this);
}

std::string Form::getName( void ) const
{
	return (_name);
}

unsigned int Form::getG2S( void ) const
{
	return (_gradeToSign);
}
unsigned int Form::getG2E( void ) const
{
	return (_gradeToExec);
}

bool Form::getSign( void ) const
{
	return (_sign);
}

void Form::beSigned(const Bureaucrat & B)
{
	std::cout << "\033[3m";
	std::cout << "Form checking ";
	std::cout << B.getName() << " able to be signed\n";
	std::cout << "\033[0m";
	if (B.getGrade() <= _gradeToSign)
	{
		_sign = true;
		std::cout << "\033[3m\tSUCCESS!\033[0m\n";
	}
	else
		throw Form::GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ( "\033[3;31mGrade Too High\033[0m" );
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ( "\033[3;31mGrade Too Low\033[0m" );
}

std::ostream & operator<<(std::ostream & os, const Form & F )
{
	os << "\n\tName : " << F.getName();
	os << "\n\tsigned : " <<  (F.getSign() ? "TRUE" : "FALSE");
	os << "\n\tGrade to sign : " <<  F.getG2S();
	os << "\n\tGrade to execute: " <<  F.getG2E() << std::endl;
	return (os);
}
