/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:08:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/01 19:23:30 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.cpp"

int main()
{
	Harl H;

	H.complain("DEBUG");
	H.complain("INFO");
	H.complain("WARNING");
	H.complain("ERROR");
	H.complain("NO");
}