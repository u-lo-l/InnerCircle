/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:37:38 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/11 09:45:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreationForm", _GRADETOSIGN, _GRADETOEXEC), _target("")
{
	std::cout << "\033[3m";
	std::cout << "ShruberryCreationForm Default Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
: Form("ShrubberyCreationForm", _GRADETOSIGN, _GRADETOEXEC), _target(target)
{
	std::cout << "\033[3m";
	std::cout << "ShruberryCreationForm Default Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & S )
: Form("ShrubberyCreationForm", _GRADETOSIGN, _GRADETOEXEC), _target(S.getTarget())
{
	std::cout << "\033[3m";
	std::cout << "ShruberryCreationForm Copy Constructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[3m";
	std::cout << "ShruberryCreationForm Default Denstructor called\n";
	std::cout << *this;
	std::cout << "\033[0m";
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm & S )
{
	std::cout << "\033[3m";
	std::cout << "ShruberryCreationForm Assign operator called\n";
	(void)&S;
	std::cout << *this << std::endl;
	std::cout << "\033[0m";
	return (*this);
}

const std::string & ShrubberyCreationForm::getTarget( void ) const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecutable(executor);
	
	std::ofstream outfile;
	std::string filename = _target + "_shrubbery";
	outfile.open(filename.c_str());
	outfile << "                                                         .\n";
	outfile << "                                              .         ;\n";
	outfile << "                 .              .              ;!     ;;\n";
	outfile << "                   ,           ,                :;!  !; \n";
	outfile << "                    :         ;                   :;!;'     .,\n";
	outfile << "           ,.        !;     !;            ;        !;'    ,;\n";
	outfile << "             ;       ;!;  !;        ,     !;    ;!;    ,!'\n";
	outfile << "              !;       !;!;      ,  ;       !;  ;!;   ,!;'\n";
	outfile << "               ;!;      !;        ;!;        ! ;!;  ,!;'\n";
	outfile << "              `!;.     ;!;     !;'         `;!;.!;'\n";
	outfile << "                 `:;!.    ;!. !@;        !; ;@!;!'\n";
	outfile << "                    `:!;.  :;bd!;          !;@!;'\n";
	outfile << "                      `@!:.  :;!.         ;@@!;' \n";
	outfile << "                        `@!.  `;@!.      ;@@!; \n";
	outfile << "                          `@!. `@!    ;@@!;\n";
	outfile << "                            ;@!. :@!  !@@!; \n";
	outfile << "                              !@bd!bd!:; \n";
	outfile << "                                #@!:;;\n";
	outfile << "                                !@@!::;\n";
	outfile << "                                !@@@!(o);  . '\n";
	outfile << "                                !@@@o!;:(.,'\n";
	outfile << "                            `.. !@@@o!::;\n";
	outfile << "                               `)@@@o!::;\n";
	outfile << "                                !@@(o)::;\n";
	outfile << "                               .!@@@@!::;\n";
	outfile << "                               ;!@@@@!::;.\n";
	outfile << "                              ;!@@@@!:;;;.\n";
	outfile << "                          ...;!@@@@@!:;;;;,..\n";
	outfile << " target : [ " << _target << " ]\n";
	outfile.close();
}

std::ostream & operator<<(std::ostream & os, const ShrubberyCreationForm & S )
{
	if (S.getTarget() == "")
		os << "Anonymous ShrubberyCreationForm\n";
	else
	{
		os << "\ttarget : " << S.getTarget();
		os << "\n\tsigned : " <<  (S.getSign() ? "TRUE" : "FALSE");
		os << "\n\tGrade to sign : " <<  S.getG2S();
		os << "\n\tGrade to execute: " <<  S.getG2E() << std::endl;
	}
	return (os);
}