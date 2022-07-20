/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringToNum.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:03:04 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 18:44:32 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSER_HPP
# define CONVERSER_HPP
# include <iostream>
# include <exception>

int ft_stoi( const std::string & s );

float ft_stof( const std::string & s );
	
double ft_stod( const std::string & s );

#endif