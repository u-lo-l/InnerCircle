/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:10:33 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/24 17:34:41 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
const unsigned int TOTAL = 30000;

void showSpans(const Span & S)
{
	std::cout << "  <" << S.shortestSpan() << ", ";
	std::cout << S.longestSpan() << ">" << std::endl;
}
int main()
{

	srand(time(0));
	Span span(TOTAL);
	std::cout << "\033[1;3mAdd numbers to span one by one\033[0m" << std::endl;
	for (unsigned int i = 0 ; i < (TOTAL / 2) ;i++)
	{
		try
		{
			span.addNumber(rand() % (2 * TOTAL));
>>>>>>> d6e02608b9539f55f7c9947674ef5663c648be20
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			break;
		}
	}
	std::cout << "\033[1;3mCheck Spans of span\033[0m" << std::endl;
	showSpans(span);
	std::cout << "\033[1;3mCreate span2 by span\033[0m" << std::endl;
	Span span2(span);
	std::cout << "\033[1;3mCheck Spans of span2\033[0m" << std::endl;
	showSpans(span2);
	std::cout << "\033[1;3mAdd a number span2\033[0m" << std::endl;
	span2.addNumber(-span2.longestSpan());
	std::cout << "\033[1;3mCheck Spans of span2\033[0m" << std::endl;
	showSpans(span2);
	std::cout << "\033[1;3massign span to span2\033[0m" << std::endl;
	span2 = span;
	std::cout << "\033[1;3mCheck Spans of span2\033[0m" << std::endl;
	showSpans(span2);
	std::cout << "\033[1;3mAdding numbers to span with pointer of array\033[0m" << std::endl;
	const int ARRSIZE = 10;
	int * arr = new int[ARRSIZE];
	for (int i = 0 ; i < ARRSIZE ; i++)
		arr[i] = -(rand() % 100 * 2 + 50);
	span.addNumber(arr, arr + ARRSIZE);
	delete arr;
	std::cout << "\033[1;3mCheck Spans of span\033[0m" << std::endl;
	showSpans(span);
	span.showInfo();
	std::cout << "\033[1;3mAdding numbers to span with Iterator of std::vector\033[0m" << std::endl;
	const int VECSIZE = 3;
	std::vector<int> * vec = new std::vector<int>;
	for (int i = 0 ; i < VECSIZE ; i++)
	{
		int r = -(rand() % 100 + 200);
		std::cout << "\t" << r << std::endl;
		vec->push_back(r);
	}
	span.addNumber(vec->begin(), vec->end());
	delete vec;
	std::cout << "\033[1;3mCheck Spans of span\033[0m" << std::endl;
	showSpans(span);
	span.showInfo();
}