/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:39 by esmirnov          #+#    #+#             */
/*   Updated: 2022/01/17 13:37:14 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buffer;
	char		*line;
	int			n;

	n = 1;
	if (fd <= 2 || BUFFER_SIZE == 0)
		return (NULL);
	*buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	while (n != 0 || n != "NULL")
	{	
		n = read(fd, buffer, BUFFER_SIZE);
		while (!buffer && buffer != '\n')
	}			
	return ("NULL");	
}
