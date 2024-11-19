/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:06:59 by dernst            #+#    #+#             */
/*   Updated: 2024/11/19 22:48:19 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int main(void)
//{
//	char	*fileNAME = "hello.txt";
//	int		fd = open(fileNAME,O_RDWR);
//	char	*result;
//	size_t	i;
//	i = 0;

//	while (i < 10)
//	{
//		result = get_next_line(fd);
//		i++;
//		printf("%s", result);
//	}
//}

char	*update_result(char *buffer, char *result, int fd)
{
	size_t	bytes_read;
	size_t	is_endline;
	size_t	start;
	size_t	len_buffer;

	is_endline = 0;
	start = 0;
	len_buffer = ft_strlen(buffer, 0);
	bytes_read = len_buffer;

	if (len_buffer == 0)
	{
		bytes_read = read_file(buffer, fd);
		if (bytes_read == 0)
			return (NULL);
	}
	while (is_endline == 0)
	{
		result = ft_strjoin(result, ft_substr(buffer, 0, bytes_read, &is_endline, &start));
		if (is_endline == 0)
			bytes_read = read_file(buffer, fd);
		if (bytes_read == 0)
			return(result);
	}
	buffer = ft_memmove(buffer, buffer + start, bytes_read - start);
	return (result);
}

size_t read_file(char *buffer, int fd)
{
	size_t	bytes_read;

	bytes_read = 0;
	bytes_read = read(fd, buffer,BUFFER_SIZE);
	if (bytes_read != 0)
		buffer[bytes_read] = '\0';
	return (bytes_read);
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
		buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	result = malloc(1);
	result[0] = '\0';
	
	return (update_result(buffer, result, fd));
}


