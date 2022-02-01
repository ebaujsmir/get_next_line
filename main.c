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

/* int	main()
{
	const char *filename = "texte.txt";
	int			fd; file escriptor
	char		*result;
	int	i = 0;

	fd = open(filename, O_RDONLY);
	printf("open done\n fd: %d\n", fd);
	while (i < 5)
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
		free(result);
		i++;
	}
    close (fd);
	printf("close done\n");
	return (0);
} */

int main(void)
{
	int fd;
	int i = 0;

	fd = open("texte.txt", O_RDONLY);
	printf("File opened\nfd = %d\n", fd);
	while (i < 5)
	{
		printf("%s", get_next_line(fd));
		i++;
		printf("i = %d\n", i);
	}
	close(fd);
	return (0);
}

