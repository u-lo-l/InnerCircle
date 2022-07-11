/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringToNum.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:03:04 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/12 02:40:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSER_HPP
# define CONVERSER_HPP
# include <iostream>
# include <exception>

int ft_stoi( const std::string & s )
	throw(std::out_of_range &, std::invalid_argument &);

float ft_stof( const std::string & s )
	throw(std::out_of_range &, std::invalid_argument &);
	
double ft_stod( const std::string & s )
	throw(std::out_of_range &, std::invalid_argument &);

#endif