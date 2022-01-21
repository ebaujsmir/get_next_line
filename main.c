/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:31 by esmirnov          #+#    #+#             */
/*   Updated: 2022/01/21 15:09:48 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int	main(int ac, char **av)
{
	const char *filename = "texte.txt";
	int			fd; /*file escriptor*/
	char		*result;

	fd = open(filename, O_RDONLY);
	printf("open done, fd: %d\n", fd);
	/*if (fd >= 0)
	{*/
	while (1)
	{		
		printf("in loop before result\n");
		result = get_next_line(fd);
		printf("after result before break\n");
		if (result == NULL)
		{	
			printf("result is NULL\n");
			break;
		}
		printf("%s", result);
	}
    close (fd);
	printf("close done\n");
	return (0);
}
