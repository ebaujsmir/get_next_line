/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:31 by esmirnov          #+#    #+#             */
/*   Updated: 2022/02/08 14:53:53 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

/* int	main()
{
	const char *filename = "texte.txt";
	int			fd;
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
}*/

/* int main(void)
{
	int fd;
	int i = 0;
	char	*str;

	fd = open("texte.txt", O_RDONLY);
	printf("File opened\nfd = %d\n", fd);
	str = get_next_line(fd);
	while (i < 5)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		i++;
		printf("i = %d\n", i);

	}
	free (str);
	close(fd);
	return (0);
}*/


// int	main(void)
// {
// 	int		fd;
// 	char	*str;
	
// 	fd = open("texte1.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	// printf("test\n");
// 	if (str)
// 	{
// 		while (str[0])
// 		{
// 			printf("%s", str);
// 			free(str);
// 			str= get_next_line(fd);
// 		}
// 		printf("sigsev ?\n");
// 	}
// 	free(str);
// 	close(fd);
// 	return (0);
// }

int			main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("texte1.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}


