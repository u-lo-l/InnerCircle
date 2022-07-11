/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:30:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 09:36:05 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
# include "Form.hpp"
# include <string>

class ShrubberyCreationForm : public Form
{
private:
	const static unsigned int _GRADETOSIGN = 145;
	const static unsigned int _GRADETOEXEC = 137;
	std::string _target;
	ShrubberyCreationForm();
public:
	explicit ShrubberyCreationForm(const std::string & target);
	ShrubberyCreationForm( const ShrubberyCreationForm & S );
	~ShrubberyCreationForm();
	ShrubberyCreationForm & operator=( const ShrubberyCreationForm & S );

	const std::string & getTarget( void ) const;
	virtual void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & os, const ShrubberyCreationForm & F );


#endif