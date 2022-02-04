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
char	*ft_read(int fd, char *storage);
char	*ft_strjoin(char *storage, char *buffer);
int		ft_strlen(char *str);
int		ft_parse(char *str);
char	*ft_copy_before_n(char *storage);
char	*ft_copy_after_n(char *storage, char *line);

#endif
