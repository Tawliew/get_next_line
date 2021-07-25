/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizfern <lfluiz.lf@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:53:14 by luizfern          #+#    #+#             */
/*   Updated: 2021/07/24 16:18:20 by luizfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include	<fcntl.h>
# include	<stdio.h>
char	*get_next_line(int fd);

#endif
