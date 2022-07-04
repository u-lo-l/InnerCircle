/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:31:24 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/04 15:13:50 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char ** argv)
{
	Harl H;

	if (argc != 2)
		return (1);
	H.complain(argv[1]);
	return (0);
}
