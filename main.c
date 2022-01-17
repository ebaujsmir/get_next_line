/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:31 by esmirnov          #+#    #+#             */
/*   Updated: 2022/01/17 13:48:26 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(int ac, char *av)
{
	const char *filename = "texte.txt";
	int			fd; /*file escriptor*/

	fd = open(filename, O_RDONLY);
	if (fd >= 2)
	{
		while (get_next_line)
		get_next_line(fd);	
	}
	else
		printf("ERREUR");
    close (fd);
	return (0);
}
