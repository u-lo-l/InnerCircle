/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:31:08 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 09:54:52 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	const static unsigned int _GRADETOSIGN = 72;
	const static unsigned int _GRADETOEXEC = 45;
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm( const std::string & target );
	RobotomyRequestForm( const RobotomyRequestForm & S );
	~RobotomyRequestForm();
	RobotomyRequestForm & operator=( const RobotomyRequestForm & S );

	const std::string & getTarget( void ) const;
	virtual void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & os, const RobotomyRequestForm & F );
#endif

