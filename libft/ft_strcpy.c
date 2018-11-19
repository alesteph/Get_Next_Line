/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:57:46 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/06 16:57:52 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned long i;

	i = -1;
	while (++i < ft_strlen(src))
		dest[i] = src[i];
	dest[ft_strlen(src)] = '\0';
	return (dest);
}
