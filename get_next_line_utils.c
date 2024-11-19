/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:12:00 by dernst            #+#    #+#             */
/*   Updated: 2024/11/19 22:05:15 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len, size_t *is_endline, size_t *buffer_start)
{
	char	*str;
	char *src;
	size_t	i;

	i = 0; 
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	
	len++;
	
	src = s + start;
	if (len > 1)
	{
		while (i < len - 1 && src[i] && src[i])
		{
			str[i] = src[i];
			if (src[i] == '\n')
			{
				*is_endline = 1;
				i++;
				break;
			}
			i++;	
		}
	}
	str[i] = '\0';
	*buffer_start = i; 
	return (str);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL && n == 0)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			((char *)dest)[--i] = ((char *)src)[--n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	((char *)dest)[i] = '\0';
	return (dest);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1, 1);
	len_s2 = ft_strlen(s2, 1);
	str = malloc((len_s1 + len_s2) + 1);
	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (s1[j] && len_s1)
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] && len_s2)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str, int type)
{
	size_t i;
	
	i = 0;

	if (type == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
			{
				i++;
				return (i);
			}
			i++;
		}	
	}
		while (str[i])
			i++;
	return (i);
}
