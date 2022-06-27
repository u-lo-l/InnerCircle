/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:03:16 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/27 17:11:49 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

const std::string & ft_replace(std::string & source, std::string & const s1, std::string & const s2)
{
	const size_t s1_len = s1.length();
	size_t	start = 0;
	while (source.find(s1, start) != std::string::npos)
}