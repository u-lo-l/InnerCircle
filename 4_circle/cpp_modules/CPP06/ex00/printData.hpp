/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:02:40 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/12 06:06:50 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTDATA_HPP
# define PRINTDATA_HPP

# include "stringToNum.hpp"
# include <limits>

void printChar( const std::string & literal )
	throw(std::out_of_range &, std::invalid_argument &);
void printInt( const std::string & literal )
	throw(std::out_of_range &, std::invalid_argument &);
void printFloat( const std::string & literal )
	throw(std::out_of_range &, std::invalid_argument &);
void printDouble( const std::string & literal )
	throw(std::out_of_range &, std::invalid_argument &);

#endif