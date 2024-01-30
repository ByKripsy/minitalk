/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:16:19 by mbouchet          #+#    #+#             */
/*   Updated: 2024/01/24 12:55:46 by mbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static int	countwords(const char *s, char sep)
{
	int		count;
	char	*cs;

	cs = (char *) s;
	count = 0;
	if (cs[0] != sep && cs[0] != 0)
	{
		cs = ft_strchr(cs, sep);
		count++;
	}
	while (cs && cs[0])
	{
		if (cs[1] != sep && cs[1])
			count++;
		cs = ft_strchr(&cs[1], sep);
	}
	return (count);
}

static size_t	ft_strlensep(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**populatetab(char **tab, int wcnt, const char *s, char c)
{
	int		j;
	size_t	len;
	int		i;

	i = 0;
	j = 0;
	if (!tab)
		return (NULL);
	while (j < wcnt && tab)
	{
		while (s[i] && s[i] == c)
			i++;
		len = ft_strlensep((char *) &s[i], c);
		tab[j] = ft_substr((char *) s, i, len);
		if (tab[j] == NULL)
		{
			ft_freetab((void **) tab);
			return (NULL);
		}
		i = i + len;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wcnt;

	if (!s)
		return (NULL);
	wcnt = countwords(s, c);
	tab = malloc((wcnt + 1) * sizeof(char *));
	tab = populatetab(tab, wcnt, s, c);
	if (tab == NULL)
		return (NULL);
	return (tab);
}
