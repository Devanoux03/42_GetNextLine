/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:52 by dernst            #+#    #+#             */
/*   Updated: 2024/11/20 15:47:18 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
// get_next_line
char	*get_next_line(int fd);
int		read_file(char *buffer, int fd);
char	*update_result(char **buffer, char *result, int fd);

// get_next_line_utils
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len, size_t *is_endline, size_t *buffer_start);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str, int type);
void	*ft_calloc(size_t nmemb, size_t size);

#endif