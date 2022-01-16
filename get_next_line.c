#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*final_line;
	int			n;

	if (fd <= 2 || BUFFER_SIZE == 0)
		return (NULL);
	*buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	n = read(fd, buffer, BUFFER_SIZE); 
}
