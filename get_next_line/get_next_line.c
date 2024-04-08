/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yawang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:27:43 by yawang            #+#    #+#             */
/*   Updated: 2024/04/08 18:42:08 by yawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	t_list	*stash = NULL;
	char			*line;
	int				readed;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_stash(fd, &stash, &readed);
	if (stash == NULL)
		return (NULL);
	// 2. extract from stash to line
	// 3. clean up stash
	return (line);
}

/* Use read() to add characters to the stash */

void	read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buffer;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return;
while (!found_newline(*stash) && *readed_ptr != 0)
	{
		*readed_ptr = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*stash == NULL && *readed_ptr == 0) || *readed_ptr == -1)
		{
			free(buffer);
			return;
		}
		buffer[*readed_ptr] = "\0";
	}
}



#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("tests/simple", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break;
		free(line);
	}
	return (0);
}