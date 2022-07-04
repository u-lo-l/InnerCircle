/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:31:24 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:07:15 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();

		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	// system("leaks violence");
	return (0);
}
