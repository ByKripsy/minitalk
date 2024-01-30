/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:04:03 by mbouchet          #+#    #+#             */
/*   Updated: 2024/01/24 12:56:40 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == 0)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	i = 0;
	while (*s)
	{
		i += write(1, &(*s), 1);
		s++;
	}
	return (i);
}

int	ft_putfloat(float nb)
{
	int	count;

	if (nb < 0)
	{
		write(1, "-", 1);
		return (ft_putfloat(-nb) + 1);
	}
	count = ft_putnbr_base((long)nb, "0123456789");
	count += ft_putchar('.');
	count += ft_putnbr_base((long)((nb - (long)nb) * 10000), "0123456789");
	return (count);
}

int	ft_putnbr_base(long nb, char *base)
{
	int	count;
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (nb < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr_base(-nb, base) + 1);
	}
	else if (nb < len)
		return (ft_putchar(base[nb]));
	else
	{
		count = ft_putnbr_base(nb / len, base);
		return (count + ft_putnbr_base(nb % len, base));
	}
}
