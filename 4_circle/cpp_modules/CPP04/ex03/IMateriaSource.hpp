/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 06:13:05 by dkim2             #+#    #+#             */
/*   Updated: 2022/07/10 06:15:41 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMateriaSource
# define IMateriaSource
# include "AMateria.hpp"
# include <iostream>

class IMateriaSource
{
public:
	virtual ~IMateriaSource();

	virtual void learnMateria(Amateria * A) = 0;
	virtual AMateria * createMateria(std::string & type) = 0;
};

#endif