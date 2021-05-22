/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshegunt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:49:49 by kshegunt          #+#    #+#             */
/*   Updated: 2021/03/05 16:49:52 by kshegunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first_part(char *src)
{
	int		i;
	char	*arr;

	i = 0;
	while (src && src[i] && src[i] != '\n')
		++i;
	if (!(arr = malloc((i + 1))))
		return (NULL);
	i = 0;
	while (src && src[i] && src[i] != '\n')
	{
		arr[i] = src[i];
		++i;
	}
	arr[i] = '\0';
	return (arr);
}

char	*another_part(char *src)
{
	char	*arr;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] && src[i] != '\n')
		++i;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	len = ft_strlen(src) - i;
	if (!(arr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	++i;
	j = 0;
	while (src[i])
		arr[j++] = src[i++];
	arr[j] = '\0';
	free(src);
	return (arr);
}

int		get_next_line(int fd, char **line)
{
	int				byte_was_read;
	char			*buf;
	static	char	*src[70000];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((byte_was_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte_was_read] = '\0';
		src[fd] = ft_strjoin(src[fd], buf);
		if (ft_strchr(src[fd], '\n') || ft_strchr(src[fd], '\0'))
			break ;
	}
	free(buf);
	if (byte_was_read < 0)
		return (-1);
	*line = first_part(src[fd]);
	src[fd] = another_part(src[fd]);
	if (!byte_was_read && !src[fd])
		return (0);
	return (1);
}
