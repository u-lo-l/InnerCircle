/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:25:17 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 04:06:21 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
private:
	int	_index;
	std::string _ideas[100];
public:
	Brain();
	~Brain();
	Brain( const Brain & B );
	Brain &operator=( const Brain & B );
	int			getIndex() const;
	std::string getIdea( int i ) const ;
	void setIdea( std::string str );
};

#endif