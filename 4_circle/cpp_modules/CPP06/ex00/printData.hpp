/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printData.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:02:40 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/20 19:36:22 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTDATA_HPP
# define PRINTDATA_HPP
# include <string>

void printChar( const std::string & literal );
void printInt( const std::string & literal );
void printFloat( const std::string & literal );
void printDouble( const std::string & literal );

#endif