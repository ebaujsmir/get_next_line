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

#include <stdio.h> /* ! to be deleted */

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	static char	*hold_buffer;
	char		*buffer;
	char		*line;
	int			i;	
	
}			list_read;

char	*get_next_line(int fd);
char	*line_read(int fd, char *hold_buffer, char *line);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		parse(char *buffer, char *hold_buffer);

			

#endif