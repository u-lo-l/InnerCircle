/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:29:11 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:05:52 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie * zombieHorde( int N, std::string name )
{
	Zombie * horde = new Zombie[N];

	for (int i = 0 ; i < N ; horde[i++].setname(name));
	for (int i = 0 ; i < N ; horde[i++].announce());
	return (horde);
}
