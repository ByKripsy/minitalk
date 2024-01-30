/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:59:01 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/12 14:59:41 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static int	ft_putnbr_ptr(unsigned long long ptr, char *base)
{
	int					count;
	unsigned long long	len;

	len = 0;
	while (base[len])
		len++;
	if (ptr < len)
		return (ft_putchar(base[ptr]));
	else
	{
		count = ft_putnbr_ptr(ptr / len, base);
		return (count + ft_putnbr_ptr(ptr % len, base));
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int			count;

	if (ptr == 0)
		count = ft_putstr("(nil)");
	else
	{
		count = ft_putstr("0x");
		count += ft_putnbr_ptr(ptr, "0123456789abcdef");
	}
	return (count);
}
