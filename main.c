/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:01:31 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/21 17:06:02 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;
	int		fd[3];
	char	*line;

	i = -1;
	if (ac >= 2)
	{
		while (i < 3)
			fd[++i] = open(++*av, O_RDONLY);
		i = -1;
		while (get_next_line(fd[++i], &line) > 0 && i < 3)
		{
			write(1, "*", 1);
			if (i == 2)
				i = -1;
			ft_putendl(line);
			free(line);
		}
		i = -1;
		while (++i < 3)
			close(fd[i]);
	}
	else
		ft_putstr_fd("Missing file.\n", 2);
	return (0);
}
