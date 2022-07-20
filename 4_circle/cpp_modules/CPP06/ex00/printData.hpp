/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:02:40 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/19 18:44:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTDATA_HPP
# define PRINTDATA_HPP

# include "stringToNum.hpp"
# include <limits>

void printChar( const std::string & literal );
void printInt( const std::string & literal );
void printFloat( const std::string & literal );
void printDouble( const std::string & literal );

#endif