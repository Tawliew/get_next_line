/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizfern <lfluiz.lf@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:37:34 by luizfern          #+#    #+#             */
/*   Updated: 2021/07/24 16:20:27 by luizfern         ###   ########.fr       */
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
	printf ("\n\n\nreturn of gnl: %s",get_next_line(fd));
}
