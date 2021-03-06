/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 17:09:12 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strappend(char *front, char *end)
{
	int		f_size;
	int		e_size;
	int		i;

	if (!front && !end)
		return (NULL);
	f_size = gnl_strlen(front);
	e_size = gnl_strlen(end);
	front = gnl_strrealloc(front, f_size + e_size);
	if (!front)
		return (NULL);
	i = -1;
	while (++i < e_size)
		front[f_size + i] = end[i];
	return (front);
}

int	gnl_cutstr(char *origin, char **front, char **rear, char c)
{
	char	*temp;

	temp = gnl_strchr(origin, c);
	if (temp == NULL)
		return (0);
	*front = gnl_substr(origin, 0, temp + 1 - origin);
	temp = gnl_substr(temp + 1, 0, gnl_strlen(temp + 1));
	free(origin);
	*rear = gnl_substr(temp, 0, gnl_strlen(temp));
	free(temp);
	return (1);
}

char	*get_next_line(int fd)
{
	int			read_status;
	char		*temp;
	char		*curr_line;
	static char	*next_line;

	curr_line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	temp = gnl_strcalloc(BUFFER_SIZE);
	if (!temp)
		return (NULL);
	read_status = read(fd, temp, BUFFER_SIZE);
	next_line = gnl_strappend(next_line, temp);
	free(temp);
	if (gnl_cutstr(next_line, &curr_line, &next_line, '\n'))
		return (curr_line);
	else if (read_status >= 1)
		return (get_next_line(fd));
	if (gnl_strlen(next_line))
		curr_line = gnl_substr(next_line, 0, gnl_strlen(next_line));
	free(next_line);
	next_line = NULL;
	return (curr_line);
}
