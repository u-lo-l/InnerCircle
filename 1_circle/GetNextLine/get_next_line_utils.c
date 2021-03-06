/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:57:01 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/10 22:27:09 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strcalloc(int len)
{
	char	*new_str;
	int		i;

	if (len < 0)
		return (NULL);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i <= len)
		new_str[i++] = 0;
	return (new_str);
}

char	*gnl_strrealloc(char *str, int new_len)
{
	char	*new;
	int		i;
	int		len;

	if (new_len < 0)
		return (NULL);
	len = gnl_strlen(str);
	if (new_len < len)
		new_len = len;
	new = gnl_strcalloc(new_len);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = str[i];
	free(str);
	return (new);
}

char	*gnl_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = gnl_strlen((char *)s);
	if (start >= slen)
		len = 0;
	else if (start + len > slen)
		len = slen - start;
	substr = gnl_strcalloc(len);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && start + i < slen)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}