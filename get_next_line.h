/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:49 by esmirnov          #+#    #+#             */
/*   Updated: 2022/01/21 17:46:15 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

#include <stdio.h> /* ! to be deleted */

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int	ft_parse(char *str);
int	error_check(int fd, char *buffer, char *hold_buff);
char	*ft_copy(char *hold_buff);
/* char	*line_split(char *hold_buf);*/
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
