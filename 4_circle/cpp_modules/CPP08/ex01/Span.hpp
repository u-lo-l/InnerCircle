/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:14:32 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 18:16:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <exception>

class Span
{
private:
    unsigned _size;
    const unsigned int _capacity;
    std::vector<int> _arr;
    Span( void );
public:
    Span( unsigned int N );
    ~Span();
    Span( const Span & s);
    Span & operator=( const Span & s);

    struct tooManyElements : public std::exception
    { const char * what() const throw(); };
    struct notEnoughElemnts : public std::exception
    { const char * what() const throw(); };

    void addNumber( const int & a );
    template <typename Iterator>
    void addNumber( Iterator begin, Iterator end);

    unsigned int shortestSpan( void ) const;
    unsigned int longestSpan( void ) const;
    
    unsigned int getSize( void ) const;
    unsigned int getCapacity( void ) const;
};

// 들어온 iterator를 이용해서 추가되는 원소의 개수(n)을 확인하고
// size + n이 N을 넘어가면 추가하지 않고 예외를 발생한다.
template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
    unsigned int n = 0;
    for (Iterator i = begin ; i != end ; i++)
        n++;
    if (_arr.size() + n > _capacity)
        throw (tooManyElements());
    _arr.insert(_arr.end(), begin, end);
    _size += n;
}


#endif