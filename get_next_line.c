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

int	ft_parse(char *str)
{
	int	i;
	
	i = 0;
	while (str)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str)
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(storage) + ft_strlen(buffer) + 1));
	if (!str)
		return (NULL);
	while (storage)
	{
		str[i] = storage[i];
		i++;
	}
	while (buffer)
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	free(storage);
	return (str);
}

char *ft_read(int fd, char *storage)
{
	char		*buffer;
	int			nbytes_read;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbytes_read = 1; 
	while (nbytes_read > 0 && ft_parse(storage) == 0)
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
		return(NULL);
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
		free (storage);
		return (NULL);
	}
	j = 0;
	i = ft_strlen(line);
	temp = malloc (sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!temp)
		return (NULL);
	while (temp[i + j])
	{
		temp[j] = temp[i + j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (storage == 0)
	{	
		storage = malloc(sizeof(char));
		if (!storage)
			return(NULL);
		storage[0] = '\0';
	}
	storage = ft_read(fd, storage);
	line = ft_copy_before_n(storage);
	storage = ft_copy_after_n(storage, line);
	return (line);
}
