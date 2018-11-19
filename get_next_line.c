/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:11:31 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/19 17:05:37 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //debug

int		end_of_line(t_list *lst, int fd)
{
	int		i;
	char	*str;

	i = -1;
	while (lst && lst->content_size != (size_t)fd)
		lst = lst->next;
	str = lst->content;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

char	*send_line(t_list **lst, int fd)
{
	char	*str;
	int		len;
	int		end;

	end = end_of_line(*lst, fd);
	while (*lst && (*lst)->content_size != (size_t)fd)
		*lst = (*lst)->next;
	len = ft_strlen((*lst)->content);
	if (!(str = (char *)malloc(sizeof(char) * end + 1)))
		return (NULL);
	str = ft_strncpy(str, (*lst)->content, end);
	(*lst)->content = ft_strdup((*lst)->content + end + 1);
	str[end] = '\0';
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int				rd;
	static t_list	*lst = NULL;
	char			*tmp;
	char			buffer[BUFF_SIZE + 1];

	ft_bzero(buffer, BUFF_SIZE + 1);
	if (lst && end_of_line(lst, fd) >= 0)
	{
		if (!(*line = send_line(&lst, fd)))
			return (-1);
		return (1);
	}
	rd = read(fd, buffer, BUFF_SIZE);
	if (!lst)
	{
		lst = ft_lstnew(buffer, rd + 1);
		lst->content_size = (size_t)fd;
	}
	else
	{
		tmp = lst->content;
		lst->content = (void *)ft_strjoin(lst->content, buffer);
		free(tmp);
	}
	return ((rd > 0) ? get_next_line(fd, line) : 0);
}
