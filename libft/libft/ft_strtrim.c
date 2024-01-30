/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:34:34 by mbouchet          #+#    #+#             */
/*   Updated: 2023/11/08 15:34:24 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static int	is_in_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	i;

	if (s1 == 0)
		return (0);
	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1[len] && is_in_set(s1[len], set) == 1 && len > 0)
		len--;
	if (len == 0)
		return (ft_strdup("\0"));
	while (s1[i] && is_in_set(s1[i], set) == 1)
		i++;
	trim = ft_substr(s1, i, (len - i) + 1);
	return (trim);
}
