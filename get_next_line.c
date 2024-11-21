/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:06:59 by dernst            #+#    #+#             */
/*   Updated: 2024/11/21 21:20:31 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(char **buffer, int fd, char **result)
{
	int	bytes_read;

	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read > 0)
		(*buffer)[bytes_read] = '\0';
	if (bytes_read <= 0)
	{
		free(*buffer);
		*buffer = NULL;
		if (bytes_read == -1)
		{
			free(*result);
			*result = NULL;
		}
	}
	return (bytes_read);
}

size_t	get_buffer(char *buffer, char **line, int bytes_read, size_t *is_end)
{
	char	*temp_result;
	size_t	buffer_start;

	buffer_start = 0;
	temp_result = ft_substr(buffer, bytes_read, is_end, &buffer_start);
	*line = ft_strjoin(*line, temp_result);
	free(temp_result);
	temp_result = NULL;
	return (buffer_start);
}

char	*update_result(char **buffer, char *result, int fd)
{
	int		bytes_read;
	size_t	is_end;
	size_t	start;

	is_end = 0;
	start = 0;
	bytes_read = ft_strlen(*buffer, 0);
	if (bytes_read == 0)
	{
		bytes_read = read_file(buffer, fd, &result);
		if (bytes_read <= 0)
			return (free(result), NULL);
	}
	while (is_end == 0)
	{
		start = get_buffer(*buffer, &result, bytes_read, &is_end);
		if (is_end == 0)
			bytes_read = read_file(buffer, fd, &result);
		if (bytes_read == 0)
			return (result);
		if (bytes_read == -1)
			return (NULL);
	}
	*buffer = ft_memmove(*buffer, *buffer + start, bytes_read - start);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	if (fd < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	result = ft_calloc(1, sizeof(char));
	result[0] = '\0';
	result = update_result(&buffer, result, fd);
	return (result);
}
