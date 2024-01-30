/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:11:54 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/03 15:04:58 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
	}
	if (ln / 10 == 0)
	{
		c = ln + '0';
		ft_putchar_fd(c, fd);
	}
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		c = ln % 10 + '0';
		ft_putchar_fd(c, fd);
	}
}
