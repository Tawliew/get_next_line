#include "get_next_line.h"
static	char	*before_selector(char *persist)
{
	char	*current_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!persist)
		return (NULL);
	while (persist[i] && persist[i] != '\n')
		i++;
	if (persist[i] == '\n')
		i++;
	current_line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!current_line)
		return (NULL);
	while (persist[j] && persist[j] != '\n')
	{
		current_line[j] = persist[j];
		j++;
	}
	if (persist[j] == '\n')
		current_line[j] = persist[j];
	return (current_line);
}

static	char	*after_selector(char *persist)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!persist)
		return (NULL);
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
	while (persist[i] != '\0')
		next_line[j++] = persist[i++];
	free(persist);
	return (next_line);
}

static char	*end_verifier(char *persist, ssize_t size_read, char *current_line)
{
	if (!ft_strlen(current_line) == 0 && persist && size_read == 0)
	{
		free(current_line);
		return (NULL);
	}
	else
		return (current_line);
}

static char	*sec_verifier(int fd)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*buffer;
	static char	*persist;
	ssize_t		size_read;

	buffer = sec_verifier(fd);
	if (!buffer)
		return (NULL);
	size_read = 1;
	while (size_read != 0 && !ft_custom_strchr(persist, '\n'))
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
	current_line = before_selector(persist);
	persist = after_selector(persist);
	current_line = end_verifier(persist, size_read, current_line);
	return (current_line);
}
