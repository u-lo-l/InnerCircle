/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:31:11 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 09:35:54 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	const static unsigned int _GRADETOSIGN = 25;
	const static unsigned int _GRADETOEXEC = 5;
	std::string _target;
	PresidentialPardonForm();
public:
	explicit PresidentialPardonForm(const std::string & target);
	PresidentialPardonForm( const PresidentialPardonForm & S );
	~PresidentialPardonForm();
	PresidentialPardonForm & operator=( const PresidentialPardonForm & S );

	const std::string & getTarget( void ) const;
	virtual void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & os, const PresidentialPardonForm & F );

#endif