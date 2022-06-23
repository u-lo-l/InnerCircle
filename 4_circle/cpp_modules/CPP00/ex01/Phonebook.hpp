/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:44:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/23 15:13:13 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

#include <iostream>
#include <string>
#include "contact.hpp"


class Phonebook
{
private :
	const static int MAXCONTS = 3;
	Contact _contacts[MAXCONTS];
	int		_numOfConts;
	int		_oldestIndex;
public :
	Phonebook ();
	~Phonebook ();

	bool	addContact(void);
	bool	searchContact(void) const;
};

#endif
