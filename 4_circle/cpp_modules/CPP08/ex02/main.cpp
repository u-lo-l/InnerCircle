/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:41:38 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/24 23:18:34 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <cmath>

void	intTest();
void	stringTest();
void	doubleTest();
void	subjectTest();

int main()
{
	std::cout << "\033[1;33mmint TEST\033[0m" << std::endl;
	intTest();
	std::cout << "\033[1;33mstd::string TEST\033[0m" << std::endl;
	stringTest();
	std::cout << "\033[1;33mdouble TEST\033[0m" << std::endl;
	doubleTest();
	std::cout << "\033[1;33msubject TEST\033[0m" << std::endl;
	subjectTest();
}

void intTest()
{
	MutantStack<int> M;
	for(int i = 1 ; i <= 10 ; i++)
		M.push(i * i);

	std::cout << "MutantStack size : " << M.size() << std::endl;
	if (M.size() == 0)
		return ;
	std::cout << "==========traverse==========" << std::endl;
	MutantStack<int>::iterator iter = M.begin();
	for (; iter != M.end(); iter++)
		std::cout << "[ " << *iter << " ]" << std::endl;
	std::cout << "======Member functions======" << std::endl;
	{
		std::cout << "1) operator=" << std::endl;
		MutantStack<int> Mcopy = M;
		std::cout << "    MutantStack Copy size : " << Mcopy.size() << std::endl;
		if (Mcopy.size() == 0)
			return ;
		std::cout << "    ==========traverse==========" << std::endl;
		MutantStack<int>::iterator iter = Mcopy.begin();
		for (; iter != Mcopy.end(); iter++)
			std::cout << "    [ " << *iter << " ]" << std::endl;

		std::cout << "2) top" << std::endl;
		std::cout << "    M.top() : " << M.top() << std::endl;

		std::cout << "3) empty" << std::endl;
		MutantStack<int> E;
		std::cout << "    E : " <<(E.empty() ? "" : "NOT ") << "EMPTY" << std::endl;
		std::cout << "    M : " <<(M.empty() ? "" : "NOT ") << "EMPTY" << std::endl;

		std::cout << "4) size" << std::endl;
		std::cout << "    M.size() : " << M.size() << std::endl;

		std::cout << "5) push" << std::endl;
		M.push(121);
		std::cout << "    M.top() : " << M.top() << std::endl;

		std::cout << "6) pop" << std::endl;
		M.pop();
		std::cout << "    M.top() : " << M.top() << std::endl;
	}
}

void	stringTest()
{
	MutantStack<std::string> M;
	for(int i = 0 ; i < 10 ; i++)
	{
		std::string str = "STRING #";
		str += static_cast<char>('0' + i);
		M.push(str);
	}

	std::cout << "MutantStack size : " << M.size() << std::endl;
	if (M.size() == 0)
		return ;
	std::cout << "==========traverse==========" << std::endl;
	MutantStack<std::string>::iterator iter = M.begin();
	for (; iter != M.end(); iter++)
		std::cout << "[ " << *iter << " ]" << std::endl;
	std::cout << "======Member functions======" << std::endl;
	{
		std::cout << "1) operator=" << std::endl;
		MutantStack<std::string> Mcopy = M;
		std::cout << "    MutantStack Copy size : " << Mcopy.size() << std::endl;
		if (Mcopy.size() == 0)
			return ;
		std::cout << "    ==========traverse==========" << std::endl;
		MutantStack<std::string>::iterator iter = Mcopy.begin();
		for (; iter != Mcopy.end(); iter++)
			std::cout << "    [ " << *iter << " ]" << std::endl;

		std::cout << "2) top" << std::endl;
		std::cout << "    M.top() : " << M.top() << std::endl;

		std::cout << "3) empty" << std::endl;
		MutantStack<std::string> E;
		std::cout << "    E : " <<(E.empty() ? "" : "NOT ") << "EMPTY" << std::endl;
		std::cout << "    M : " <<(M.empty() ? "" : "NOT ") << "EMPTY" << std::endl;

		std::cout << "4) size" << std::endl;
		std::cout << "    M.size() : " << M.size() << std::endl;

		std::cout << "5) push" << std::endl;
		M.push("STRING #10");
		std::cout << "    M.top() : " << M.top() << std::endl;

		std::cout << "6) pop" << std::endl;
		M.pop();
		std::cout << "    M.top() : " << M.top() << std::endl;
	}
}

void	doubleTest()
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(3);
	MutantStack<double> M;
	for(int i = 1 ; i <= 10 ; i++)
		M.push(sqrt(i));

	std::cout << "MutantStack size : " << M.size() << std::endl;
	if (M.size() == 0)
		return ;
		
	std::cout << "==========traverse==========" << std::endl;
	MutantStack<double>::iterator iter = M.begin();
	for (; iter != M.end(); iter++)
		std::cout << "[ " << *iter << " ]" << std::endl;

	std::cout << "======Member functions======" << std::endl;
	{
		std::cout << "1) operator=" << std::endl;
		MutantStack<double> Mcopy = M;
		std::cout << "    MutantStack Copy size : " << Mcopy.size() << std::endl;
		if (Mcopy.size() == 0)
			return ;
		std::cout << "    ==========traverse==========" << std::endl;
		MutantStack<double>::iterator iter = Mcopy.begin();
		for (; iter != Mcopy.end(); iter++)
			std::cout << "    [ " << *iter << " ]" << std::endl;

		std::cout << "2) top" << std::endl;
		std::cout << "    M.top() : " << M.top() << std::endl;

		std::cout << "3) empty" << std::endl;
		MutantStack<double> E;
		std::cout << "    E : " <<(E.empty() ? "" : "NOT ") << "EMPTY" << std::endl;
		std::cout << "    M : " <<(M.empty() ? "" : "NOT ") << "EMPTY" << std::endl;

		std::cout << "4) size" << std::endl;
		std::cout << "    M.size() : " << M.size() << std::endl;

		std::cout << "5) push" << std::endl;
		M.push(sqrt(11));
		std::cout << "    M.top() : " << M.top() << std::endl;

		std::cout << "6) pop" << std::endl;
		M.pop();
		std::cout << "    M.top() : " << M.top() << std::endl;
	}
}

void	subjectTest()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack.top() : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size() : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "mstack.top() : " << mstack.top() << std::endl;
	std::cout << "mstack.size() : " << mstack.size() << std::endl;
	std::cout << "s.top() : " << s.top() << std::endl;
	std::cout << "s.size() : " << s.size() << std::endl;
	return ;
}