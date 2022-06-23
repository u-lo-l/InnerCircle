/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:39:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/22 22:15:41 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACT_HPP_
# define _CONTACT_HPP_
# include <iostream>
# include <string>

class Contact
{
private :
	std::string _names[3];
	std::string _phoneNumber;
	std::string _darkestSecret;
public :
	Contact() {};
	~Contact() {};
	bool	fillContact();
	void	printNames(void) const;
};

#endif
