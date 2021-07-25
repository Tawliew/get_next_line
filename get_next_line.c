/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizfern <lfluiz.lf@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:52:56 by luizfern          #+#    #+#             */
/*   Updated: 2021/07/25 01:18:40 by luizfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

char	*str_line(char *buf)
{
	size_t counter[2];
	char *line;

	counter[0] = 0;
	counter[1] = 0;

	while(buf[counter[0]] != '\n')
	{
		write(1, &buf[counter[0]], 1);
		counter[0]++;
	}
	//return(counter[0]);
	
	line = calloc(sizeof(char), (counter[0] + 1));
	if (!line)
		return (NULL);
	while (counter[0] > counter[1])
	{
		line[counter[1]] = buf[counter[1]];
		counter[1]++;
	}
	line[counter[1]] = '\n';
	return (line);
}


char	*get_next_line(int fd)
{
	ssize_t size_read;
	char *buf;
	char *line;

	buf = calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size_read = read(fd, buf, BUFFER_SIZE);
	line = str_line(buf);
	printf("\n the text in the line is: %s", line);
	printf("\n the size of the string is: %ld", size_read);
	return (buf);
}
