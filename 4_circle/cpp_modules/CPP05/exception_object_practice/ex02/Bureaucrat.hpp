/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:27:00 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 14:46:38 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <stdexcept>
# include <ostream>

class Form;

class Bureaucrat
{
private:
	static const unsigned int _MAXGRADE = 1;
	static const unsigned int _MINGRADE = 150;
	const std::string _name;
	unsigned int _grade;
	class GradeTooHighException : public std::exception
	{
	public :
		const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public :
		const char * what() const throw();
	};
public:
	Bureaucrat();
	explicit Bureaucrat(const std::string & name, int grade = Bureaucrat::_MINGRADE);
	virtual ~Bureaucrat();
	Bureaucrat( const Bureaucrat & B );
	Bureaucrat & operator = (const Bureaucrat & B );
	
	virtual std::string getName( void ) const;
	virtual unsigned int getGrade( void ) const;

	void increaseGrade( unsigned int amount = 1);
	void decreaseGrade( unsigned int amount = 1);
	void signForm( Form & F ) const;
	void executeForm( const Form & form);
};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & B);

#endif