/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:55:34 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/08 01:31:54 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static char	*ft_empty(void)
{
	char	*ptr;

	ptr = (char *) malloc(1);
	if (ptr)
		ptr[0] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == 0)
		return (0);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_empty());
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	while (i < len)
	{
		sub[i] = ((char *) s)[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
