/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:22:33 by mbouchet          #+#    #+#             */
/*   Updated: 2023/10/31 13:15:36 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cpy;

	cpy = (unsigned char *) s;
	while (n--)
		*cpy++ = c;
	return (s);
}
