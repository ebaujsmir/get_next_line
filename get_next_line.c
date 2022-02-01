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

/*int	error_check(int fd, char *hold_buff, char *line)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || fd == 1 || fd == 2 || fd > FD_MAX)
		return (1);
	if (!hold_buff)
		return (1);
	if (!line)
		return (1);
	return (0);
}*/

/* char	*line_split(char *hold_buff)
{
	char	*cpy;
	char	*temp;
	int		i;
	int		len;

	i = 0;
	while (hold_buff && hold_buff != '\n')
		i++;
	len = i + 1;
	if (hold_buff[i] == '\n')
	{
		cpy = ft_substr(hold_buff, 0, len);
		temp = ft_substr(hold_buff, len,  
		free (holf_buff);
		hold_buff = 
	}
	if (hold_buff == 0)
		*hold_buff = ft_strdup(&[i]);
	free (temp);
	return(cpy);
}*/ 

char	*ft_copy_before_n(char *hold_buf)
{
	char	*final_line;
	char	*temp;
	int		i;
	int		n;

	i = 0;
	while (hold_buf[i] != '\0' && hold_buf[i] != '\n')
		i++;
	n = strlen(holf_buff);
	if (n != i)
	{
		temps = malloc (sizeof(char) * (i + 2);
		if (temps == NULL)
			retrun(NULL);
		i = 0;
		while (hold_buf[i] != '\n')
		{
			temps[i] = hold_buf[i];
			i++;
		}
		temps [i] = '\n';
		temps[i++] = '\0';
	return (final_line);
}

char	ft_copy_after_n(char *holf_buff)
{
	
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*hold_buf;
	int			nbytes_read;

	if (hold_buf == 0)
		hold_buf = ft_strdup("\0");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	nbytes_read = 1; /* read(fd, buffer, BUFFER_SIZE);*/
	while (nbytes_read > 0 && !ft_parse(hold_buff))
	{
		nbytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nbytes_read] = '\0';
		hold_buf = ft_strjoin(hold_buf, buffer);
		/* nbytes_read = read(fd, buffer, BUFFER_SIZE);*/
	}
	line = ft_copy_before_n(hold_buf);
	hold_buf = ft_copy_after_n(hold_buf);
	return (line);
	/*return (ft_return(hold_buffer, line, nbytes_read));*/
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

/* commint 2


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
		}
	}
	return (line);
} */
