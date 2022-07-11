/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:49:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 04:51:03 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat()
: _name(""), _grade(Bureaucrat::_MINGRADE)
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Default Constructor called\n";
	std::cout << "\tname  : " << _name << std::endl;
	std::cout << "\tgrade : " << _grade << std::endl;
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
	std::cout << "\tname  : " << _name << std::endl;
	std::cout << "\tgrade : " << _grade << std::endl;
	std::cout << "\033[0m";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Default Destructor called\n";
	std::cout << "\033[0m";
}

Bureaucrat::Bureaucrat( const Bureaucrat & B )
: _name(B.getName()), _grade(B.getGrade())
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Copy Constructor called\n";
	std::cout << "\tname  : " << _name << std::endl;
	std::cout << "\tgrade : " << _grade << std::endl;
	std::cout << "\033[0m";
}

// _name은 const string인데 이게 복사가 되나?
// _grade만 복사
Bureaucrat & Bureaucrat::operator = (const Bureaucrat & B )
{
	std::cout << "\033[3m";
	std::cout << "Bureaucrat Assign operator called (" << _name << " <- " << B.getName() << ")\n";
	std::cout << "only grade will be copied. not name\n";
	std::cout << "\033[0m";
	this->_grade = B.getGrade();
	std::cout << "\033[3m";
	std::cout << "\tname  : " << _name << std::endl;
	std::cout << "\tgrade : " << _grade << std::endl;
	std::cout << "\033[0m";
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
	std::cout << "Bureaucrat increaseGrade(" << amount << ") called\n";
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
	std::cout << "Bureaucrat decreaseGrade(" << amount << ") called\n";
	std::cout << "\033[0m";
	if (_grade + amount > _MINGRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += amount;
	std::cout << "\033[3m";
	std::cout << "\tgrade : " << last << " -> " << _grade << std::endl;
	std::cout << "\033[0m";
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ( "\033[3;31m[ERR] Grade Too High\033[0m" );
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( "\033[3;31m[ERR]Grade Too Low\033[0m" );
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & B)
{
	os << "Name : " << B.getName() << ", Grade : " <<  B.getGrade();
	return (os);
}
