/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:55:31 by esmirnov          #+#    #+#             */
/*   Updated: 2022/02/04 14:41:10 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
	{	
		storage = malloc(sizeof(char) * 1);
		if (!storage)
			return(NULL);
		storage[0] = '\0';
	}
	storage = ft_read(fd, storage);
	line = ft_copy_before_n(storage);
	storage = ft_copy_after_n(storage, line);
	return (line);
}
