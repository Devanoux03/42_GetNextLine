/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:07:42 by dernst            #+#    #+#             */
/*   Updated: 2024/11/14 18:30:11 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(long int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		n++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	strreverse(char *str, int sign)
{
	size_t	i;
	size_t	j;
	char	temp;

	if (ft_strlen(str) == 1)
		return ;
	i = sign;
	j = ft_strlen(str) - 1;
	while (i <= (ft_strlen(str) / 2) - 1 + sign)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static void	manage_sign(int *sign, size_t *i, long int *num)
{
	if (*num < 0)
	{
		*sign = 1;
		*num *= -1;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	size_t		i;
	int			sign;
	char		*result;
	long int	num;

	num = n;
	sign = 0;
	i = 0;
	manage_sign(&sign, &i, &num);
	result = malloc(sizeof(char) * (intlen(num) + sign + 1));
	if (!result)
		return (NULL);
	if (num == 0)
		return (result[0] = num + '0', result[1] = '\0', result);
	while (num > 0)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	result[i] = '\0';
	if (sign == 1)
		result[0] = '-';
	strreverse(result, sign);
	return (result);
}
