/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:25:17 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 16:43:36 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
private:
	unsigned int	_numOfIdeas;
	std::string _ideas[100];
public:
	Brain();
	~Brain();
	Brain( const Brain & B );
	Brain &operator=( const Brain & B );
	int			getIndex() const;
	std::string getIdea( unsigned int i ) const ;
	void addIdea( std::string str );
};

#endif