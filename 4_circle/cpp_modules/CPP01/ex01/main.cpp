/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:36:38 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/15 15:39:14 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	{
		Zombie * horde;
	
		horde = zombieHorde(7, "Orde");
		for (int i = 0 ; i < 7 ; i++)
			horde[i].announce();
		delete[] horde;
	}
	// system( "leaks zombiehorde" );
	return (0);
}
