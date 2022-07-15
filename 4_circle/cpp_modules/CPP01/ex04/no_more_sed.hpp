/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_more_sed.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:22:56 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 19:26:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NO_MORE_SED_HPP
# define NO_MORE_SED_HPP
# include <string>

void exit_err(const std::string str);

bool read_from_file(const std::string & filename, std::string & temp);

void ft_replace(std::string & source, const std::string & s1, const std::string &s2);

#endif
