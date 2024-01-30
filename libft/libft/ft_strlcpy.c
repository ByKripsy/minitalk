/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:39:33 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/08 14:26:58 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	srclen;

	n = 0;
	srclen = ft_strlen(src);
	if (dst == 0 || src == 0)
		return (0);
	if (size != 0)
	{
		while (src[n] && n < size - 1)
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = '\0';
	}
	return (srclen);
}
