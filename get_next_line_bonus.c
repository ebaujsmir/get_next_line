/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:55:31 by esmirnov          #+#    #+#             */
/*   Updated: 2022/02/09 11:34:42 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage[OPEN_MAX];

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
	{
		storage[fd] = malloc(sizeof(char) * 1);
		if (!storage[fd])
			return (NULL);
		storage[fd][0] = '\0';
	}
	storage[fd] = ft_read(fd, storage[fd]);
	line = ft_copy_before_n(storage[fd]);
	storage[fd] = ft_copy_after_n(storage[fd], line);
	if (storage[fd] == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_read(int fd, char *storage)
{
	char		*buffer;
	int			nbytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbytes_read = 1;
	while (nbytes_read > 0 && !ft_parse(storage, '\n'))
	{
		nbytes_read = read(fd, buffer, BUFFER_SIZE);
		if (nbytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*ft_copy_before_n(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc (sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_copy_after_n(char *storage, char *line)
{
	char	*temp;
	int		i;
	int		j;

	if (!storage[0])
	{
		free(storage);
		return (NULL);
	}
	j = 0;
	i = ft_strlen(line);
	temp = malloc (sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!temp)
		return (NULL);
	while (storage[i + j])
	{
		temp[j] = storage[i + j];
		j++;
	}
	temp[j] = '\0';
	free (storage);
	return (temp);
}
