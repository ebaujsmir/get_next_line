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

static int	ft_parse(char *str)
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

char	*ft_strjoin(char *holder, char buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(holder) + ft_strlen(buffer) + 1));
	if (!str)
	{
		free(buffer); /* to be checked */
		return (NULL);
	}
	while (holder)
	{
		str[i] = holder[i];
		i++;
	}
	while (buffer)
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	free(holder);
	return (str);
}

static char *ft_read(int fd, char holder)
{
	char		*buffer;
	int			nbytes_read;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))
	if (!buffer)
	{
		free(holder);
		return (NULL);
	}
	nbytes_read = 1; 
	while (nbytes_read > 0 && !ft_parse(holder))
	{
		nbytes_read = read(fd, buffer, BUFFER_SIZE);
		if (nbyte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes_read] = '\0';
		holder = ft_strjoin(holder, buffer);
	}
	free(buffer);
	return (holder);
}

static char	*ft_copy_before_n(char *holder)
{
	char	*line;
	int		i;

	i = 0;
	while (holder[i] != '\0' && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
		i++;
	line = malloc (sizeof(char) * (i + 1));
	if (!line)
		return(NULL);
	i = 0;
	while (holder[i] != '\0' && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/* len includes "\n" , temp[i + 1] to stqrt from the char after "\n" */
static char	*ft_copy_after_n(char *holder)
{
	char	*end;
	char	*temp;
	int		len;
	int		i;

	temp = ft_strchr(holder, '\n');
	len = ft_strlen(temp);
	end = malloc (sizeof(char) * len);
	if (!end)
		return (NULL);
	i = 0;
	while (temp[i] != '\0')
	{
		end[i] = temp[i + 1];
		i++;
	}
	end[i] = '\0';
	return (end);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*holder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (holder == 0)
	{	
		holder = malloc(sizeof(char));
		if (!holder)
			return(NULL);
		holder[0] = '\0';
	}
	holder = ft_read(fd, holder);
	line = ft_copy_before_n(holder);
	holder = ft_copy_after_n(holder, line);
	return (line);
}