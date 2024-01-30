/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:45 by mbouchet          #+#    #+#             */
/*   Updated: 2024/01/24 12:55:23 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	getvalue(char c, int base)
{
	int	val;

	val = -1;
	c = ft_tolower(c);
	if (c >= '0' && c <= '9')
		val = c - 48;
	if (c >= 'a' && c <= 'z')
		val = c - 87;
	if (val >= base)
		val = -1;
	return (val);
}

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (getvalue(str[i], base) != -1 && str[i])
	{
		result = result * base + getvalue(str[i], base);
		i++;
	}
	return (result * sign);
}
