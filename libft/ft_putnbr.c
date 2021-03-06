/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesteph <alesteph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:41:44 by alesteph          #+#    #+#             */
/*   Updated: 2018/11/12 16:10:31 by alesteph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		ft_putnbr(n * -1);
	}
	else if (n < 10)
		ft_putchar(n % 10 + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}
