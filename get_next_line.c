/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:39 by esmirnov          #+#    #+#             */
/*   Updated: 2022/01/21 18:04:36 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*hold_buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0 )
		return (NULL);
	//hold_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//if (!hold_buffer)
	//	return (NULL);	
	if (!line)
	{
		line = malloc (sizeof(char) * 1);
		if (line == NULL) 
			return (NULL);
	}
	my_read(fd, hold_buffer, line); // attention to the loop line & line1//	free(buffer); // voir pour ligne et hold_buffer str (strjoin) 
	if (line == NULL)
		return (NULL);
	else 
		return (line);
}

void *my_read(int fd, char *hold_buffer, char *line)
{
	char		*buffer;
	int			nbr_read;
	int			i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbr_read = read(fd, buffer, BUFFER_SIZE);
	if ( nbr_read == 0)
		return (NULL);
	while (nbr_read > 0)
	{	
		i = 0;

		buffer[BUFFER_SIZE] = '\0';
		while (!buffer && (buffer[i] != '\n'))
		{
			hold_buffer[i] = buffer[i];
			i++;
		}
		line = ft_strjoin(line, hold_buffer);
		if (i < BUFFER_SIZE)
		{
			while (i < BUFFER_SIZE)
			{
				hold_buffer[i] = 
			}
		}*/
	}
	return (line);
}

parce



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
			free(buffer);*/ /* voir pour ligne et hold_buffer */
/*			return (NULL);
		}
		while (!buffer && buffer != '\n')
		{
			
		}
	}			
	return ("NULL");
} */

/*

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*hold_buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0 )
		return (NULL);
	hold_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!hold_buffer)
		return (NULL);	
	if (!line)
	{
		line = malloc (sizeof(char) * 1);
		if (line == NULL) 
			return (NULL);
	}
	my_read(fd, hold_buffer, line); // attention to the loop line & line1//	free(buffer); // voir pour ligne et hold_buffer str (strjoin) 
	if (line == NULL)
		return (NULL);
	else 
		retur (line);
}

void *my_read(int fd, char *hold_buffer, char *line)
{
	char		*buffer;
	int			nbr_read;
	int			i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbr_read = read(fd, buffer, BUFFER_SIZE);
	if ( nbr_read == 0)
		return (NULL);
	while (nbr_read > 0)
	{	
		i = 0;

		buffer[BUFFER_SIZE] = '\0';
		while (!buffer && (buffer[i] != '\n'))
		{
			hold_buffer[i] = buffer[i];
			i++;
		}
		line = ft_strjoin(line, hold_buffer);
		if (i < BUFFER_SIZE)
		{
			while (i < BUFFER_SIZE)
			{
				hold_buffer[i] = 
			}
		}
	}
	return (line);
}

parce */

