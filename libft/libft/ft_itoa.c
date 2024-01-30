/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:25:06 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/08 01:28:57 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static int	get_size(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i += 1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		i;
	long	tmp;
	long	ln;

	ln = n;
	i = get_size(ln);
	tmp = n;
	if (ln < 0)
		ln *= -1;
	nb = malloc(i + 1);
	if (nb == 0)
		return (0);
	if (tmp < 0)
		nb[0] = '-';
	nb[i] = '\0';
	while (ln > 9 && i--)
	{
		nb[i] = '0' + ln % 10;
		ln /= 10;
	}
	nb[i - 1] = '0' + ln;
	return (nb);
}
