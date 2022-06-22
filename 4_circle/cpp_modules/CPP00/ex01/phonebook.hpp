/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:44:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/22 18:01:19 by dkim2            ###   ########.fr       */
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

	void	addContact(void);
	void	searchContact(void) const;
	int		getnoc() {return (_numOfConts);};
	int		getoldest() {return (_oldestIndex);};
};

#endif
