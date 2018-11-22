/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:11:31 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/22 18:33:44 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	end_of_line(t_list *lst, int fd)
{
	int		i;
	char	*str;

	i = -1;
	while (lst && lst->content_size != (size_t)fd)
		lst = lst->next;
	if (lst && lst->content)
	{
		str = lst->content;
		while (str[++i])
			if (str[i] == '\n')
				return (i);
	}
	return (-1);
}

static char	*send_line(t_list *lst, int fd)
{
	t_list	*tmp;
	char	*str;
	char	*save;
	int		end;

	tmp = lst;
	while (tmp && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	end = (end_of_line(tmp, fd) == -1) ? ft_strlen(tmp->content) :
		end_of_line(tmp, fd);
	if (!(str = (char *)malloc(sizeof(char) * end + 1)))
		return (NULL);
	str = ft_strncpy(str, tmp->content, end);
	if (end_of_line(tmp, fd) == -1)
		ft_bzero(tmp->content, end);
	else
	{
		save = tmp->content;
		tmp->content = ft_strdup(tmp->content + end + 1);
		free(save);
	}
	str[end] = '\0';
	return (str);
}

static int	check_fd(t_list *lst, int fd)
{
	while (lst)
	{
		if (lst->content_size == (size_t)fd)
			return ((int)ft_strlen(lst->content));
		lst = lst->next;
	}
	return (-1);
}

static void	read_it(t_list **lst, const char *buffer, int rd, int fd)
{
	t_list	*new;
	char	*tmp;

	if (check_fd(*lst, fd) == -1)
	{
		new = ft_lstnew(buffer, rd + 1);
		new->content_size = (size_t)fd;
		ft_lstadd(lst, new);
	}
	else
	{
		new = *lst;
		while (new && new->content_size != (size_t)fd)
			new = new->next;
		tmp = new->content;
		new->content = (void *)ft_strjoin(new->content, buffer);
		free(tmp);
	}
}

int			get_next_line(const int fd, char **line)
{
	int				rd;
	static t_list	*lst = NULL;
	char			buffer[BUFF_SIZE + 1];

	ft_bzero(buffer, BUFF_SIZE + 1);
	if (lst && (end_of_line(lst, fd) >= 0))
	{
		if (!(*line = send_line(lst, fd)))
			return (-1);
		return (1);
	}
	if ((rd = read(fd, buffer, BUFF_SIZE)) < 0)
		return (-1);
	read_it(&lst, buffer, rd, fd);
	if (ft_isempty(lst->content) != 0 && rd == 0)
	{
		if (!(*line = send_line(lst, fd)))
			return (-1);
		return (1);
	}
	return ((rd > 0) ? get_next_line(fd, line) : 0);
}
