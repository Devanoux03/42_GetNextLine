/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:49:17 by dernst            #+#    #+#             */
/*   Updated: 2024/11/15 22:48:24 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char	*fileNAME = "hello.txt";
	int fd = open(fileNAME,O_RDWR);
	
	if (fd == -1)
	{
		printf("\nFailed Opening File !");	
	}
	else
	{
		printf("Sucess Opening File !");
	}
	
	char buffer[1024];
	
	int bytesRead = read(fd, buffer, sizeof(buffer));
	buffer[bytesRead] = '\0';

	printf("%d bytes read:\n", bytesRead);
	printf("File Content: \n%s\n", buffer);
}