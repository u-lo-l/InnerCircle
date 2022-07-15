/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:29:11 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 15:41:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie * zombieHorde( int N, std::string name )
{
	Zombie * horde = new Zombie[N];

	if (!horde)
		return (0);
	for (int i = 0 ; i < N ;i++)
	{
		std::stringstream ss;
		ss << i;
		std::string id;
		ss >> id;
		id = name + " #" + id;
		horde[i].setname(id);
	}
	return (horde);
}
