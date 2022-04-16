/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:02:11 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/15 20:12:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <sys/time.h>

long	get_ltime(void)
{
	struct timeval	time;
	long			mili_sec;
	
	gettimeofday(&time, NULL);
	mili_sec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (mili_sec);
}