/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:49:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 15:06:47 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat()
: _name(""), _grade(Bureaucrat::_MINGRADE)
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Default Constructor called\n";
	std::cout << "\033[0m";
}

Bureaucrat::Bureaucrat(const std::string & name, int grade)
: _name(name), _grade(grade)
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Constructor with parameter called (";
	std::cout << name << ", " << grade << ")\n";
	std::cout << "\033[0m";
	if (_grade > Bureaucrat::_MINGRADE)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < Bureaucrat::_MAXGRADE)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "\033[3m";
	std::cout << *this;
	std::cout << "\033[0m" << std::endl ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Default Destructor called" << std::endl;
	std::cout << "\t" << *this << std::endl;
	std::cout << "\033[0m";
}

Bureaucrat::Bureaucrat( const Bureaucrat & B )
: _name(B.getName()), _grade(B.getGrade())
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	std::cout << *this;
	std::cout << "\033[0m";
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & B )
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Assign operator called (" << _name << " <- " << B.getName() << ")\n";
	std::cout << "only grade will be copied. not name" << std::endl;
	std::cout << "\033[0m";
	this->_grade = B.getGrade();
	std::cout << "\033[3m";
	std::cout << *this;
	std::cout << "\033[0m" << std::endl;
	return (*this);
}

std::string Bureaucrat::getName( void ) const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void Bureaucrat::increaseGrade( unsigned int amount )
{
	unsigned int last = _grade;
	
	std::cout << "\033[3m";
	std::cout << "Bureaucrat increaseGrade(" << amount << ") called" << std::endl;
	std::cout << "\033[0m";
	if (_grade - amount < _MAXGRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade -= amount;
	std::cout << "\033[3m";
	std::cout << "\tgrade : " << last << " -> " << _grade << std::endl;
	std::cout << "\033[0m";
}

void Bureaucrat::decreaseGrade( unsigned int amount )
{
	unsigned int last = _grade;

	std::cout << "\033[3m";
	std::cout << "Bureaucrat decreaseGrade(" << amount << ") called" << std::endl;
	std::cout << "\033[0m";
	if (_grade + amount > _MINGRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += amount;
	std::cout << "\033[3m";
	std::cout << "\tgrade : " << last << " -> " << _grade << std::endl;
	std::cout << "\033[0m";
}

void Bureaucrat::signForm( Form & F ) const
{
	try
	{
		std::cout << "\033[33m";
		F.beSigned((*this));
		std::cout << _name << " signed " << F.getName() << std::endl;
		std::cout << "\033[0m";
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[33m";
		std::cerr << _name << " couldn’t sign " << F.getName();
		std::cerr << " because " << e.what() << std::endl;
		std::cout << "\033[0m";
	}
	
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ( "\033[3;31mGrade Too High\033[0m" );
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( "\033[3;31mGrade Too Low\033[0m" );
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & B)
{
	if (B.getName() == "")
		os << "Anonymous Bureaucrat";
	else
		os << "Name : " << B.getName() << ", Grade : " <<  B.getGrade();
	return (os);
}
