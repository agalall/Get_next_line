/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:43:49 by agalall           #+#    #+#             */
/*   Updated: 2022/01/23 17:51:04 by agalall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char *str, int *n)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	s = ft_substr(str, 0, i + 1);
	*n = i;
	return (s);
}

static char	*ft_remain(char *str, int *n)
{
	char	*s;

	s = ft_substr(str, *n + 1, ft_strlen(str));
	free(str);
	return (s);
}

static char	*ft_fd(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		rd;

	rd = 1;
	while (rd > 0 && !ft_strchr(str, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		buff[rd] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
			str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_fd(fd, str);
	if (!str[0])
	{
		free(str);
		str = (NULL);
		return (NULL);
	}
	n = 0;
	line = ft_line(str, &n);
	str = ft_remain(str, &n);
	return (line);
}
