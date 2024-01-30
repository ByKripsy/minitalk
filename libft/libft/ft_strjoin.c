/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:11:37 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/08 15:52:16 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (str == 0)
		return (str);
	while (s1[i])
	{
		str[i] = ((char *) s1)[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = ((char *) s2)[j];
		j++;
	}
	str[len] = '\0';
	return (str);
}
