/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:02:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/24 23:21:40 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	
	explicit MutantStack( const Container & C = Container() );
	MutantStack( const std::stack<T, Container> & S );
	MutantStack( const MutantStack & M );
	~MutantStack();
	MutantStack & operator=( const MutantStack & M );

	//========================
	// STACK MEMBER OBJECT (protected)
	// c
	//========================
	// STACK MEMBER FUNCITON (public)
	// operator=
	// top { return (c.back); }
	// empty
	// size
	// push
	// pop
	//========================
	
	iterator begin();
	iterator end();
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack( const Container & C )
: std::stack<T, Container>( C ) { }

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack( const std::stack<T, Container> & S )
: std::stack<T, Container>( S ) { }

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack( const MutantStack<T, Container> & M )
: std::stack<T, Container>( M ) { }

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
MutantStack<T, Container> & MutantStack<T, Container>::operator=( const MutantStack<T, Container> & M )
{
	if ( this == &M )
		return (*this);
	std::stack<T, Container>::operator=(M);
	return (*this);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

#endif