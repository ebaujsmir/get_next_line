/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:39 by esmirnov          #+#    #+#             */
/*   Updated: 2022/01/20 15:54:47 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*hold_buffer;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{	
		while (!buffer && buffer != '\n')
		{
			*hold_buffer = *buffer;
		}
		ft_strjoin(line, hold_buffer);
	}
	free(buffer); /* voir pour ligne et hold_buffer*/
	return (NULL);
}

/* main zith bytes_n vriabl for return of read fonction

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*hold_buffer;
	char		*buffer;
	char		*line;
	int			bytes_n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_n = 1;
	while (bytes_n != 0)
	{	
		bytes_n = read(fd, buffer, BUFFER_SIZE);
		if (bytes_n < 0)
		{	
			free(buffer);/* voir pour ligne et hold_buffer 
			return (NULL);
		}
		while (!buffer && buffer != '\n')
		{
			
		}
	}			
	return ("NULL");
} */
