/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:32:40 by mbouchet          #+#    #+#             */
/*   Updated: 2023/12/14 16:01:44 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

static int	check_format(const char *s, va_list	args)
{
	int	i;

	i = 0;
	if (*s == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (*s == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (*s == 'p')
		i = ft_putptr(va_arg(args, unsigned long long));
	else if (*s == 'd' || *s == 'i')
		i = ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (*s == 'f')
		i = ft_putfloat(va_arg(args, double));
	else if (*s == 'u')
		i = ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (*s == 'x')
		i = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*s == 'X')
		i = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*s == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += check_format(s, args);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}
