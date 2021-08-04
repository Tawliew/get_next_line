/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizfern <lfluiz.lf@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 02:47:06 by luizfern          #+#    #+#             */
/*   Updated: 2021/08/04 02:55:41 by luizfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	i;

	i = 0;
	pointer = (void *)malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	while (i < (nmemb * size))
	{
		((unsigned char *)pointer)[i] = '\0';
		i++;
	}
	return (pointer);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	if (!str)
		return (NULL);
	if (c == 0)
	{
		i = 0;
		while (str[i])
			i++;
		return ((char *)str + i);
	}
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_custom_strjoin(char *s1, char *s2)
{
	char	*strconcat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	strconcat = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!strconcat)
		return (NULL);
	while (s1 && s1[i])
	{
		strconcat[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		strconcat[i++] = s2[j++];
	free(s1);
	return (strconcat);
}

