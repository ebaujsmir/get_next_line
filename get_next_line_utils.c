/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:10:00 by esmirnov          #+#    #+#             */
/*   Updated: 2022/01/21 11:57:26 by esmirnov         ###   ########.fr       */
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

/*
char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len1 + 1);
	ft_strlcat(str, s2, len1 + len2 + 1);
	free(s1);
	return (str);
}

char	*ft_strdup(char *src)
{
	int		index;
	char	*dest;

	index = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (0);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (char)c))
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destcpy;
	const char	*srccpy;

	destcpy = dest;
	srccpy = src;
	if (!dest && !src)
		return (0);
	while (n--)
		*destcpy++ = *srccpy++;
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstlen >= size)
		return (size + srclen);
	while (src[i] != '\0' && dstlen + i < size - 1)
	{	
		dst[dstlen + i] = src [i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
} */
