/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:17:36 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:05:06 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie * zombieInHeap;
	zombieInHeap = new Zombie("Hombie");
	zombieInHeap->announce();
	delete zombieInHeap;

	Zombie zombieInStack("Sombie");
	zombieInStack.announce();

	// system("leaks zombie");
	return (0);
}
