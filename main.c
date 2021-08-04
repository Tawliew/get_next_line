/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizfern <lfluiz.lf@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:37:34 by luizfern          #+#    #+#             */
/*   Updated: 2021/08/04 02:28:13 by luizfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char const **argv)
{
	int fd;
	//ssize_t readi;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
	{
		fd = 2;
		return (fd);

	}
	int i = 0;
	while (++i < 10)
	{
		//printf("o valor de i e: %d\n", i);
		printf ("\n\nreturn of gnl: %s\n\n",get_next_line(fd));
	}
///	printf ("\n\n\nreturn of gnl: %s",get_next_line(fd));
}
