/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizfern <lfluiz.lf@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 02:47:06 by luizfern          #+#    #+#             */
/*   Updated: 2021/08/04 20:52:47 by luizfern         ###   ########.fr       */
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
		((unsigned char *)pointer)[i++] = '\0';
	return (pointer);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	ft_custom_strchr(char *str, char c)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_custom_strjoin(char *s1, char *s2)
{
	char	*strconcat;
	int		i;
	int		j;
	int		size_strconcat;

	i = 0;
	j = 0;
	size_strconcat = (ft_strlen(s1) + ft_strlen(s2));
	if (!s1 && !s2)
		return (NULL);
	strconcat = (char *)ft_calloc((size_strconcat + 1), sizeof(char));
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
