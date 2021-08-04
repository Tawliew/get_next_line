#include "get_next_line.h"

char	*before_line_breaker(char *persist)
{
	char	*current_line;
	int		i;

	if (!persist)
		return (NULL);
	i = 0;
	while (persist[i] && persist[i] != '\n')
		i++;
	if (persist[i] == '\n')
		i++;
	current_line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!current_line)
		return (NULL);
	i = 0;
	while (persist[i] && persist[i] != '\n')
	{
		current_line[i] = persist[i];
		i++;
	}
	if (persist[i] == '\n')
		current_line[i] = persist[i];
	return (current_line);
}

char	*after_line_breaker(char *persist)
{
	char	*next_line;
	int		i;
	int		j;

	if (!persist)
		return (NULL);
	i = 0;
	while (persist[i] && persist[i] != '\n')
		i++;
	if (!persist[i])
	{
		free(persist);
		return (NULL);
	}
	next_line = (char *)ft_calloc((ft_strlen(persist) - i), sizeof(char));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (persist[i] != '\0')
		next_line[j++] = persist[i++];
	free(persist);
	return (next_line);
}

char	*verify_end_file(char *persist, ssize_t ret, char *current_line)
{
	if (!persist && ret == 0 && ft_strlen(current_line) == 0)
	{
		free(current_line);
		return (NULL);
	}
	else
		return (current_line);
}

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*buffer;
	static char	*persist;
	ssize_t		size_read;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	size_read = 1;
	while (size_read != 0 && !ft_strchr(persist, '\n'))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size_read] = '\0';
		persist = ft_custom_strjoin(persist, buffer);
	}
	free(buffer);
	current_line = before_line_breaker(persist);
	persist = after_line_breaker(persist);
	current_line = verify_end_file(persist, size_read, current_line);
	return (current_line);
}
