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
	{
		std::cerr << "usage : ./harlFilter <message>" << std::endl;
		return (1);
	}
	if ( H.complain(argv[1]) == false)
	{
		std::cerr << "\033[31minvalid messsage : \033[0m";
		std::cerr << "message should be one of\n";
		std::cerr << "\033[3m'DEBUG', 'INFO', 'WARNING', 'ERROR', or ";
		std::cerr << "'I am not sure how tired I am today...'\033[0m\n";
		return (1);
	}
	return (0);
}
