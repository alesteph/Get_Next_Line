/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:43:40 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/19 17:06:38 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <sys/types.h>
# include <sys/uio.h>
# include "./libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
