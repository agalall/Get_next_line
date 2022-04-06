/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalall <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:16:01 by agalall           #+#    #+#             */
/*   Updated: 2022/01/23 15:59:22 by agalall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

size_t			ft_strlen(char *s);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*get_next_line(int fd);

#endif
