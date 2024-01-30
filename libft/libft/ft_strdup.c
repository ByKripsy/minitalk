/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:46:19 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/02 19:28:42 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strdup(const char *src)
{
	unsigned int		len;
	char				*cpy;

	len = 0;
	while (src[len])
		len++;
	cpy = malloc (len + 1);
	if (cpy == 0)
		return (0);
	len = 0;
	while (src[len])
	{
		cpy[len] = (char) src[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}
