/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:57:52 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 14:20:45 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{
private :
	static const unsigned int _MAXGRADE = 1;
	static const unsigned int _MINGRADE = 150;
	const std::string _name;
	const unsigned int _gradeToSign;
	const unsigned int _gradeToExec;
	bool _sign;
public :
	Form();
	Form(std::string name, unsigned int g2s, unsigned int g2e);
	Form( const Form & F );
	virtual ~Form();
	Form &operator=( const Form & F );

	virtual std::string getName( void ) const;
	unsigned int getG2S( void ) const;
	unsigned int getG2E( void ) const;
	bool getSign( void ) const;
	void beSigned( const Bureaucrat & B );

	virtual void execute(Bureaucrat const & executor) const = 0;
	void checkExecutable( const Bureaucrat & B ) const throw(std::exception);

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
	class ExecuteFailException : public std::exception
	{
	public :
		const char * what() const throw();
	};
};

#endif