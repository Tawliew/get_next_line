/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizfern <lfluiz.lf@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:53:14 by luizfern          #+#    #+#             */
/*   Updated: 2021/08/04 02:47:49 by luizfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# include	<fcntl.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stddef.h>


char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *src);
//char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_custom_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
#endif
