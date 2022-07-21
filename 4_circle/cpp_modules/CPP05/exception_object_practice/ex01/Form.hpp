/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:57:52 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/21 14:21:22 by dkim2            ###   ########.fr       */
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
	const std::string _name;			// constant name
	const unsigned int _gradeToSign;	// constant grade required to sign
	const unsigned int _gradeToExec;	// constant grade required to be executed
	bool _sign;							// boolean indicating whether it is signed
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
};

std::ostream & operator<<(std::ostream & os, const Form & F );

#endif