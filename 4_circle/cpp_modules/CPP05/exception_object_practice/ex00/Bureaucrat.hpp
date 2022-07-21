/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 03:27:00 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 12:38:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <stdexcept>
# include <ostream>

class Bureaucrat
{
private:
	const static unsigned int _MAXGRADE = 1;
	const static unsigned int _MINGRADE = 150;
	const std::string _name;
	unsigned int _grade;
	Bureaucrat();
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
	explicit Bureaucrat(const std::string & name, int grade = Bureaucrat::_MINGRADE);
	~Bureaucrat();
	Bureaucrat( const Bureaucrat & B );
	Bureaucrat & operator = (const Bureaucrat & B );
	
	std::string getName( void ) const;
	unsigned int getGrade( void ) const;
	void increaseGrade( unsigned int amount = 1);
	void decreaseGrade( unsigned int amount = 1);

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & B);

#endif