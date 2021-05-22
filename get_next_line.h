/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshegunt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:49:57 by kshegunt          #+#    #+#             */
/*   Updated: 2021/03/05 16:50:02 by kshegunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*end_line(char *src);

int		get_next_line(int fd, char **line);

int		ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s1);

char	*ft_strjoin(char *s1, char *s2);

char	*get_new_line(char *memory);

char	*get_buffer(char *s);

#endif
