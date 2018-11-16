/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:11:31 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/16 16:13:06 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //debug

int		end_of_line(char *line)
{
	int	i;

	i = -1;
	if (line)
	{
		while (line[++i])
			if (line[i] == '\n')
				return (i);
	}
	return (-1);
}

int		check_buff(char *buffer)
{
	int	end;

	if ((end = end_of_line(buffer)) >= 0)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buffer;

	if (!buffer)
		if (!(buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
	buffer[BUFF_SIZE] = 0;
	if (check_buff(buffer) == 1)
	{
		*line = ft_strncat(*line, buffer, end_of_line(buffer) + 1);
		printf("line = %s\n", *line);
		buffer = ft_memmove(buffer, buffer + end_of_line(buffer),
				ft_strlen(buffer) - end_of_line(buffer));
		return (1);
	}
	while (read(fd, buffer, BUFF_SIZE) > 0)
	{
		if (check_buff(buffer) == 1)
		{
			*line = ft_strncat(*line, buffer, end_of_line(buffer) + 1);
			buffer = ft_memmove(buffer, buffer + end_of_line(buffer),
					ft_strlen(buffer) - end_of_line(buffer));
			return (1);
		}
		*line = ft_strncat(*line, buffer, BUFF_SIZE);
	}
	free(buffer);
	return (0);
}
