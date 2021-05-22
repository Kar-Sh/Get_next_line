/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshegunt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:49:35 by kshegunt          #+#    #+#             */
/*   Updated: 2021/03/05 16:49:39 by kshegunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
		++index;
	return (index);
}

int		ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (1);
		++index;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new_str;
	size_t		f_index;
	size_t		s_index;

	if (!(new_str = malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	f_index = 0;
	s_index = 0;
	if (s1)
		while (s1[f_index])
			new_str[s_index++] = s1[f_index++];
	f_index = 0;
	if (s2)
		while (s2[f_index])
			new_str[s_index++] = s2[f_index++];
	new_str[s_index] = '\0';
	free(s1);
	return (new_str);
}
